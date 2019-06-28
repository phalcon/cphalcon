<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Db/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/AdapterInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Db adapters
 *',
    'file' => '/app/phalcon/Db/AdapterInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'AdapterInterface',
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
          'name' => 'addColumn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 21,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 21,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 21,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 21,
              'char' => 94,
            ),
          ),
          'docblock' => '**
     * Adds a column to a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 21,
                'char' => 103,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 21,
            'char' => 103,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 21,
          'last-line' => 25,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 26,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 26,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'IndexInterface',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 26,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 26,
              'char' => 91,
            ),
          ),
          'docblock' => '**
     * Adds an index to a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 26,
                'char' => 100,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 26,
            'char' => 100,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addForeignKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 31,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 31,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'reference',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ReferenceInterface',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 31,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 31,
              'char' => 104,
            ),
          ),
          'docblock' => '**
     * Adds a foreign key to a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 31,
                'char' => 113,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 31,
            'char' => 113,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addPrimaryKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 36,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 36,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'IndexInterface',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 36,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 36,
              'char' => 96,
            ),
          ),
          'docblock' => '**
     * Adds a primary key to a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 36,
                'char' => 105,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 36,
            'char' => 105,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 36,
          'last-line' => 41,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'affectedRows',
          'docblock' => '**
     * Returns the number of affected rows by the last INSERT/UPDATE/DELETE
     * reported by the database system
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 42,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 42,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
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
          'name' => 'begin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'nesting',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 47,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 47,
              'char' => 46,
            ),
          ),
          'docblock' => '**
     * Starts a transaction in the connection
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 47,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 47,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 47,
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
          'name' => 'close',
          'docblock' => '**
     * Closes active connection returning success. Phalcon automatically closes
     * and destroys active connections within Phalcon\\Db\\Pool
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 53,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 53,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
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
          'name' => 'commit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'nesting',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 58,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 58,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Commits the active transaction in the connection
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 58,
                'char' => 56,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 58,
            'char' => 56,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 58,
          'last-line' => 63,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'connect',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'descriptor',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 64,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 64,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * This method is automatically called in \\Phalcon\\Db\\Adapter\\Pdo
     * constructor. Call it when you need to restore a database connection
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 64,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 64,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 64,
          'last-line' => 68,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createSavepoint',
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
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 69,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Creates a new savepoint
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 69,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 69,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 69,
          'last-line' => 73,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createTable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 74,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 74,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 74,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Creates a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 74,
                'char' => 98,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 74,
            'char' => 98,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 74,
          'last-line' => 78,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createView',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 79,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 79,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 79,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 79,
              'char' => 93,
            ),
          ),
          'docblock' => '**
     * Creates a view
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 79,
                'char' => 102,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 79,
            'char' => 102,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 79,
          'last-line' => 83,
          'char' => 19,
        ),
        12 => 
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
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 84,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'whereCondition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 84,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 84,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 84,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 84,
              'char' => 84,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 84,
                'char' => 102,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 84,
              'char' => 102,
            ),
          ),
          'docblock' => '**
     * Deletes data from a table using custom RDBMS SQL syntax
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 84,
                'char' => 111,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 84,
            'char' => 111,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 84,
          'last-line' => 88,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'describeColumns',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 89,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 89,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 89,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Returns an array of Phalcon\\Db\\Column objects describing a table
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
                  'value' => 'ColumnInterface',
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 89,
                  'char' => 96,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 89,
                'char' => 96,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 89,
            'char' => 96,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 89,
          'last-line' => 93,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'describeIndexes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 94,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 94,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 94,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Lists table indexes
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
                  'value' => 'IndexInterface',
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 94,
                  'char' => 95,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 94,
                'char' => 95,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 94,
            'char' => 95,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 94,
          'last-line' => 98,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'describeReferences',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 99,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 99,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 99,
              'char' => 75,
            ),
          ),
          'docblock' => '**
     * Lists table references
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
                  'value' => 'ReferenceInterface',
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 99,
                  'char' => 102,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 99,
                'char' => 102,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 99,
            'char' => 102,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 99,
          'last-line' => 103,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropColumn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 104,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 104,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'columnName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 104,
              'char' => 88,
            ),
          ),
          'docblock' => '**
     * Drops a column from a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 104,
                'char' => 97,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 104,
            'char' => 97,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 104,
          'last-line' => 108,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropForeignKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 109,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 109,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'referenceName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 109,
              'char' => 95,
            ),
          ),
          'docblock' => '**
     * Drops a foreign key from a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 109,
                'char' => 104,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 109,
            'char' => 104,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 109,
          'last-line' => 113,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 114,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 114,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'indexName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 114,
              'char' => 86,
            ),
          ),
          'docblock' => '**
     * Drop an index from a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 114,
                'char' => 95,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 114,
            'char' => 95,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 114,
          'last-line' => 118,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropPrimaryKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 119,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 119,
              'char' => 73,
            ),
          ),
          'docblock' => '**
     * Drops primary key from a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 119,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 119,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 119,
          'last-line' => 123,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropTable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 124,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 124,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 124,
              'char' => 75,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ifExists',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 124,
                'char' => 97,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 124,
              'char' => 97,
            ),
          ),
          'docblock' => '**
     * Drops a table from a schema/database
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 124,
                'char' => 106,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 124,
            'char' => 106,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 124,
          'last-line' => 128,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropView',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 129,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 129,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 129,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ifExists',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 129,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 129,
              'char' => 95,
            ),
          ),
          'docblock' => '**
     * Drops a view
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 129,
                'char' => 104,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 129,
            'char' => 104,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 129,
          'last-line' => 133,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeIdentifier',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'identifier',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 134,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Escapes a column/table/schema name
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 134,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 134,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 134,
          'last-line' => 138,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeString',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'str',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 139,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Escapes a value to avoid SQL injections
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 139,
                'char' => 56,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 139,
            'char' => 56,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 139,
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
          'name' => 'execute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlStatement',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 146,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 146,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 146,
              'char' => 74,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 146,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 146,
              'char' => 96,
            ),
          ),
          'docblock' => '**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server doesn\'t
     * return any rows
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 146,
                'char' => 105,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 146,
            'char' => 105,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
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
          'name' => 'fetchAll',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlQuery',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 151,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fetchMode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '2',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 151,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 151,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 151,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 151,
              'char' => 86,
            ),
          ),
          'docblock' => '**
     * Dumps the complete result of a query into an array
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 151,
                'char' => 96,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 151,
            'char' => 96,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 151,
          'last-line' => 168,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetchColumn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlQuery',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 169,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 169,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 169,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 169,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 169,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Returns the n\'th field of first row in a SQL query result
     *
     *```php
     * // Getting count of robots
     * $robotsCount = $connection->fetchColumn("SELECT count(*) FROM robots");
     * print_r($robotsCount);
     *
     * // Getting name of last edited robot
     * $robot = $connection->fetchColumn(
     *     "SELECT id, name FROM robots order by modified desc",
     *     1
     * );
     * print_r($robot);
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 169,
                'char' => 101,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 169,
                'char' => 107,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 169,
            'char' => 107,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 169,
          'last-line' => 173,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fetchOne',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlQuery',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 174,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fetchMode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '2',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 174,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 174,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 174,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 174,
              'char' => 86,
            ),
          ),
          'docblock' => '**
     * Returns the first row in a SQL query result
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 174,
                'char' => 96,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 174,
            'char' => 96,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 174,
          'last-line' => 178,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'forUpdate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlQuery',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 179,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Returns a SQL modified with a FOR UPDATE clause
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 179,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 179,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 179,
          'last-line' => 183,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumnDefinition',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 184,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 184,
              'char' => 65,
            ),
          ),
          'docblock' => '**
     * Returns the SQL column definition from a column
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 184,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 184,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 184,
          'last-line' => 188,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumnList',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'columnList',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 189,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Gets a list of columns
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 189,
                'char' => 60,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 189,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 189,
          'last-line' => 193,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConnectionId',
          'docblock' => '**
     * Gets the active connection unique identifier
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 194,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 194,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 194,
          'last-line' => 198,
          'char' => 19,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDescriptor',
          'docblock' => '**
     * Return descriptor used to connect to the active database
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 199,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 199,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 199,
          'last-line' => 203,
          'char' => 19,
        ),
        33 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDialect',
          'docblock' => '**
     * Returns internal dialect instance
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
                  'value' => 'DialectInterface',
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 204,
                  'char' => 55,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 204,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 204,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 204,
          'last-line' => 208,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDialectType',
          'docblock' => '**
     * Returns the name of the dialect used
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 209,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 209,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 209,
          'last-line' => 213,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultIdValue',
          'docblock' => '**
     * Return the default identity value to insert in an identity column
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
                  'value' => 'RawValue',
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 214,
                  'char' => 54,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 214,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 214,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 214,
          'last-line' => 218,
          'char' => 19,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getInternalHandler',
          'docblock' => '**
     * Return internal PDO handler
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
                  'value' => '\\Pdo',
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 219,
                  'char' => 51,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 219,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 219,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 219,
          'last-line' => 223,
          'char' => 19,
        ),
        37 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNestedTransactionSavepointName',
          'docblock' => '**
     * Returns the savepoint name to use for nested transactions
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 224,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 224,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 224,
          'last-line' => 228,
          'char' => 19,
        ),
        38 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRealSQLStatement',
          'docblock' => '**
     * Active SQL statement in the object without replace bound parameters
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 229,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 229,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 229,
          'last-line' => 233,
          'char' => 19,
        ),
        39 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSQLStatement',
          'docblock' => '**
     * Active SQL statement in the object
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 234,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 234,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 234,
          'last-line' => 238,
          'char' => 19,
        ),
        40 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSQLBindTypes',
          'docblock' => '**
     * Active SQL statement in the object
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 239,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 239,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 239,
          'last-line' => 243,
          'char' => 19,
        ),
        41 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSQLVariables',
          'docblock' => '**
     * Active SQL statement in the object
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 244,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 244,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 244,
          'last-line' => 248,
          'char' => 19,
        ),
        42 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'docblock' => '**
     * Returns type of database system the adapter is used for
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 249,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 249,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 249,
          'last-line' => 253,
          'char' => 19,
        ),
        43 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'insert',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 254,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 254,
              'char' => 55,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'fields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 254,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 254,
              'char' => 70,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 254,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 254,
              'char' => 88,
            ),
          ),
          'docblock' => '**
     * Inserts data into a table using custom RDBMS SQL syntax
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 254,
                'char' => 97,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 254,
            'char' => 97,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 254,
          'last-line' => 272,
          'char' => 19,
        ),
        44 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'insertAsDict',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 273,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 273,
              'char' => 52,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 273,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 273,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Inserts data into a table using custom RBDM SQL syntax
     *
     * ```php
     * // Inserting a new robot
     * $success = $connection->insertAsDict(
     *     "robots",
     *     [
     *         "name" => "Astro Boy",
     *         "year" => 1952,
     *     ]
     * );
     *
     * // Next SQL sentence is sent to the database system
     * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
     * ```
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 273,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 273,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 273,
          'last-line' => 277,
          'char' => 19,
        ),
        45 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isNestedTransactionsWithSavepoints',
          'docblock' => '**
     * Returns if nested transactions should use savepoints
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 278,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 278,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 278,
          'last-line' => 282,
          'char' => 19,
        ),
        46 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUnderTransaction',
          'docblock' => '**
     * Checks whether connection is under database transaction
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 283,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 283,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 283,
          'last-line' => 288,
          'char' => 19,
        ),
        47 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'lastInsertId',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sequenceName',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 289,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 289,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Returns insert id for the auto_increment column inserted in the last SQL
     * statement
     *',
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 289,
          'last-line' => 293,
          'char' => 19,
        ),
        48 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'limit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlQuery',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 294,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'number',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 294,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Appends a LIMIT clause to sqlQuery argument
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 294,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 294,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 294,
          'last-line' => 298,
          'char' => 19,
        ),
        49 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listTables',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 299,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 299,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * List all tables on a database
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 299,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 299,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 299,
          'last-line' => 303,
          'char' => 19,
        ),
        50 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listViews',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 304,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 304,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * List all views on a database
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 304,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 304,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 304,
          'last-line' => 308,
          'char' => 19,
        ),
        51 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'modifyColumn',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 309,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 309,
              'char' => 71,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'column',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 309,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 309,
              'char' => 97,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'currentColumn',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ColumnInterface',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 309,
                'char' => 129,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 309,
                'char' => 137,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 309,
              'char' => 137,
            ),
          ),
          'docblock' => '**
     * Modifies a table column based on a definition
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 309,
                'char' => 146,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 309,
            'char' => 146,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 309,
          'last-line' => 315,
          'char' => 19,
        ),
        52 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'query',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlStatement',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 316,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 316,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 316,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 316,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 316,
              'char' => 94,
            ),
          ),
          'docblock' => '**
     * Sends SQL statements to the database server returning the success state.
     * Use this method only when the SQL statement sent to the server returns
     * rows
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
                  'value' => 'ResultInterface',
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 316,
                  'char' => 117,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 316,
                'char' => 117,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 316,
                'char' => 123,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 316,
            'char' => 123,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 316,
          'last-line' => 320,
          'char' => 19,
        ),
        53 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'releaseSavepoint',
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
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 321,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Releases given savepoint
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 321,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 321,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 321,
          'last-line' => 325,
          'char' => 19,
        ),
        54 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'nesting',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 326,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 326,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Rollbacks the active transaction in the connection
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 326,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 326,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 326,
          'last-line' => 330,
          'char' => 19,
        ),
        55 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollbackSavepoint',
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
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 331,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Rollbacks given savepoint
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 331,
                'char' => 60,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 331,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 331,
          'last-line' => 335,
          'char' => 19,
        ),
        56 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'sharedLock',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlQuery',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 336,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Returns a SQL modified with a LOCK IN SHARE MODE clause
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 336,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 336,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 336,
          'last-line' => 340,
          'char' => 19,
        ),
        57 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setNestedTransactionsWithSavepoints',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'nestedTransactionsWithSavepoints',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 341,
              'char' => 94,
            ),
          ),
          'docblock' => '**
     * Set if nested transactions should use savepoints
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
                  'file' => '/app/phalcon/Db/AdapterInterface.zep',
                  'line' => 341,
                  'char' => 117,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 341,
                'char' => 117,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 341,
            'char' => 117,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 341,
          'last-line' => 346,
          'char' => 19,
        ),
        58 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'supportSequences',
          'docblock' => '**
     * Check whether the database system requires a sequence to produce
     * auto-numeric values
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 347,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 347,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 347,
          'last-line' => 351,
          'char' => 19,
        ),
        59 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'tableExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 352,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 352,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 352,
              'char' => 77,
            ),
          ),
          'docblock' => '**
     * Generates SQL checking for the existence of a schema.table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 352,
                'char' => 86,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 352,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 352,
          'last-line' => 356,
          'char' => 19,
        ),
        60 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'tableOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tableName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 357,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 357,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 357,
              'char' => 77,
            ),
          ),
          'docblock' => '**
     * Gets creation options from a table
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 357,
                'char' => 87,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 357,
            'char' => 87,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 357,
          'last-line' => 361,
          'char' => 19,
        ),
        61 => 
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
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 362,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 362,
              'char' => 48,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 362,
              'char' => 56,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'whereCondition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 362,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 362,
              'char' => 79,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 362,
                'char' => 97,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 362,
              'char' => 97,
            ),
          ),
          'docblock' => '**
     * Updates data on a table using custom RDBMS SQL syntax
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 362,
                'char' => 106,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 362,
            'char' => 106,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 362,
          'last-line' => 381,
          'char' => 19,
        ),
        62 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'updateAsDict',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'table',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 382,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 382,
              'char' => 56,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'whereCondition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 382,
                'char' => 83,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 382,
              'char' => 83,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'dataTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 382,
                'char' => 105,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 382,
              'char' => 105,
            ),
          ),
          'docblock' => '**
     * Updates data on a table using custom RBDM SQL syntax
     * Another, more convenient syntax
     *
     * ```php
     * // Updating existing robot
     * $success = $connection->updateAsDict(
     *     "robots",
     *     [
     *         "name" => "New Astro Boy",
     *     ],
     *     "id = 101"
     * );
     *
     * // Next SQL sentence is sent to the database system
     * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
     * ```
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 382,
                'char' => 114,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 382,
            'char' => 114,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 382,
          'last-line' => 387,
          'char' => 19,
        ),
        63 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useExplicitIdValue',
          'docblock' => '**
     * Check whether the database system requires an explicit value for identity
     * columns
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 388,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 388,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 388,
          'last-line' => 392,
          'char' => 19,
        ),
        64 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'viewExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 393,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schemaName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 393,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/AdapterInterface.zep',
              'line' => 393,
              'char' => 75,
            ),
          ),
          'docblock' => '**
     * Generates SQL checking for the existence of a schema.view
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
                'file' => '/app/phalcon/Db/AdapterInterface.zep',
                'line' => 393,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/AdapterInterface.zep',
            'line' => 393,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Db/AdapterInterface.zep',
          'line' => 393,
          'last-line' => 394,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/AdapterInterface.zep',
      'line' => 394,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Db/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);