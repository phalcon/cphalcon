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
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 10,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 12,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Db\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 12,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 13,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 14,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Messages\\MessageInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 15,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\CriteriaInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 15,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 16,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\ModelInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 16,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 17,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\MetaDataInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 17,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 18,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\ResultsetInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 19,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\TransactionInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 19,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 20,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/ModelInterface.zep',
        'line' => 20,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 26,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\ModelInterface
 *
 * Interface for Phalcon\\Mvc\\Model
 *',
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 27,
    'char' => 9,
  ),
  12 => 
  array (
    'type' => 'interface',
    'name' => 'ModelInterface',
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
          'name' => 'appendMessage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'MessageInterface',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 32,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 32,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Appends a customized message on the validation process
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 32,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 32,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 32,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 32,
          'last-line' => 38,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'assign',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 39,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'dataColumnMap',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 39,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 39,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'whiteList',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 39,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 39,
              'char' => 87,
            ),
          ),
          'docblock' => '**
     * Assigns values to a model from an array
     *
     * @param array columnMap
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 39,
                  'char' => 108,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 39,
                'char' => 108,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 39,
            'char' => 108,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 39,
          'last-line' => 47,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'average',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 48,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 48,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Allows to calculate the average value on a column matching the specified
     * conditions
     *
     * @param array parameters
     * @return double
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'double',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 48,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 48,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 26,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'cloneResult',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'base',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 53,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 53,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 53,
              'char' => 74,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'dirtyState',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 53,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 53,
              'char' => 94,
            ),
          ),
          'docblock' => '**
     * Assigns values to a model from an array returning a new model
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 53,
                  'char' => 115,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 53,
                'char' => 115,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 53,
            'char' => 115,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 53,
          'last-line' => 61,
          'char' => 26,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'cloneResultMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'base',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 62,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 62,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'columnMap',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 62,
              'char' => 75,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'dirtyState',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 62,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 62,
              'char' => 95,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'keepSnapshots',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 62,
                'char' => 122,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 62,
              'char' => 122,
            ),
          ),
          'docblock' => '**
     * Assigns values to a model from an array returning a new model
     *
     * @param \\Phalcon\\Mvc\\Model base
     * @param array columnMap
     * @return \\Phalcon\\Mvc\\Model result
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 62,
                  'char' => 143,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 62,
                'char' => 143,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 62,
            'char' => 143,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 62,
          'last-line' => 68,
          'char' => 26,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'cloneResultMapHydrate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 69,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'columnMap',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 69,
              'char' => 76,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'hydrationMode',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 69,
              'char' => 95,
            ),
          ),
          'docblock' => '**
     * Returns an hydrated result based on the data and the column map
     *
     * @param array columnMap
     *',
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 69,
          'last-line' => 76,
          'char' => 26,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'count',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 77,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 77,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Allows to count how many records match the specified conditions
     *
     * @param array parameters
     * @return int
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 77,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 77,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 77,
          'last-line' => 83,
          'char' => 26,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'create',
          'docblock' => '**
     * Inserts a model instance. If the instance already exists in the
     * persistence it will throw an exception. Returning true on success or
     * false otherwise.
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 84,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 84,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 84,
          'last-line' => 88,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'delete',
          'docblock' => '**
     * Deletes a model instance. Returning true on success or false otherwise.
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 89,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 89,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 89,
          'last-line' => 93,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'find',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 94,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 94,
              'char' => 54,
            ),
          ),
          'docblock' => '**
     * Allows to query a set of records that match the specified conditions
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 94,
                  'char' => 79,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 94,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 94,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 94,
          'last-line' => 100,
          'char' => 26,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'findFirst',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 101,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 101,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Allows to query the first record that match the specified conditions
     *
     * @param array parameters
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 101,
                  'char' => 77,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 101,
                'char' => 77,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 101,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 101,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 101,
          'last-line' => 106,
          'char' => 26,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fireEvent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 107,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Fires an event, implicitly calls behaviors and listeners in the events
     * manager are notified
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 107,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 107,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 107,
          'last-line' => 113,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fireEventCancel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 114,
              'char' => 54,
            ),
          ),
          'docblock' => '**
     * Fires an event, implicitly calls behaviors and listeners in the events
     * manager are notified. This method stops if one of the callbacks/listeners
     * returns bool false
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 114,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 114,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 114,
          'last-line' => 119,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDirtyState',
          'docblock' => '**
     * Returns one of the DIRTY_STATE_* constants telling if the record exists
     * in the database or not
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 120,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 120,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 120,
          'last-line' => 124,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'docblock' => '**
     * Returns array of validation messages
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 125,
                  'char' => 58,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 125,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 125,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 125,
          'last-line' => 129,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModelsMetaData',
          'docblock' => '**
     * Returns the models meta-data service related to the entity instance.
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
                  'value' => 'MetaDataInterface',
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 130,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 130,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 130,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 130,
          'last-line' => 135,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOperationMade',
          'docblock' => '**
     * Returns the type of the latest operation performed by the ORM
     * Returns one of the OP_* class constants
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 136,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 136,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 136,
          'last-line' => 140,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReadConnection',
          'docblock' => '**
     * Gets internal database connection
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 141,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 141,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 141,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 141,
          'last-line' => 145,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReadConnectionService',
          'docblock' => '**
     * Returns DependencyInjection connection service used to read data
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 146,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 146,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 146,
          'last-line' => 153,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRelated',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 154,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 154,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 154,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Returns related records based on defined relations
     *
     * @param array arguments
     * @return \\Phalcon\\Mvc\\Model\\Resultset\\Simple|Phalcon\\Mvc\\Model\\Resultset\\Simple|false
     *',
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 154,
          'last-line' => 158,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSchema',
          'docblock' => '**
     * Returns schema name where table mapped is located
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 159,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 159,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 159,
          'last-line' => 163,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSource',
          'docblock' => '**
     * Returns table name mapped in the model
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 164,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 164,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 164,
          'last-line' => 168,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getWriteConnection',
          'docblock' => '**
     * Gets internal database connection
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 169,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 169,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 169,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 169,
          'last-line' => 173,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getWriteConnectionService',
          'docblock' => '**
     * Returns DependencyInjection connection service used to write data
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 174,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 174,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 174,
          'last-line' => 182,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'maximum',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 183,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 183,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Allows to get the maximum value of a column that match the specified
     * conditions
     *
     * @param array parameters
     * @return mixed
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 183,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 183,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 183,
          'last-line' => 191,
          'char' => 26,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'minimum',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 192,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 192,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Allows to get the minimum value of a column that match the specified
     * conditions
     *
     * @param array parameters
     * @return mixed
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 192,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 192,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 192,
          'last-line' => 196,
          'char' => 26,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'query',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 197,
                'char' => 56,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 197,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 197,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Create a criteria for a specific model
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 197,
                  'char' => 88,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 197,
                'char' => 88,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 197,
            'char' => 88,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 197,
          'last-line' => 201,
          'char' => 26,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'refresh',
          'docblock' => '**
     * Refreshes the model attributes re-querying the record from the database
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 202,
                  'char' => 50,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 202,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 202,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 202,
          'last-line' => 207,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'save',
          'docblock' => '**
     * Inserts or updates a model instance. Returning true on success or false
     * otherwise.
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 208,
                'char' => 35,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 208,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 208,
          'last-line' => 212,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setConnectionService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 213,
              'char' => 66,
            ),
          ),
          'docblock' => '**
     * Sets both read/write connection services
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 213,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 213,
          'last-line' => 218,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDirtyState',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'dirtyState',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 219,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets the dirty state of the object using one of the DIRTY_STATE_*
     * constants
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 219,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 219,
                'char' => 71,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 219,
                'char' => 77,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 219,
            'char' => 77,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 219,
          'last-line' => 223,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setReadConnectionService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 224,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Sets the DependencyInjection connection service used to read data
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 224,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 224,
          'last-line' => 231,
          'char' => 19,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSnapshotData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 232,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'columnMap',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 232,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 232,
              'char' => 66,
            ),
          ),
          'docblock' => '**
     * Sets the record\'s snapshot data. This method is used internally to set
     * snapshot data when the model was set up to keep snapshot data
     *
     * @param array columnMap
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 232,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 232,
          'last-line' => 236,
          'char' => 19,
        ),
        33 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTransaction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'transaction',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'TransactionInterface',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 237,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 237,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Sets a transaction related to the Model instance
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
                  'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                  'line' => 237,
                  'char' => 91,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 237,
                'char' => 91,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 237,
            'char' => 91,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 237,
          'last-line' => 241,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setWriteConnectionService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 242,
              'char' => 71,
            ),
          ),
          'docblock' => '**
     * Sets the DependencyInjection connection service used to write data
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 242,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 242,
          'last-line' => 246,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'skipOperation',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'skip',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 247,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Skips the current operation forcing a success state
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 247,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 247,
          'last-line' => 254,
          'char' => 19,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'sum',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 255,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ModelInterface.zep',
              'line' => 255,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Allows to calculate a sum on a column that match the specified conditions
     *
     * @param array parameters
     * @return double
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'double',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 255,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 255,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 255,
          'last-line' => 259,
          'char' => 26,
        ),
        37 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'validationHasFailed',
          'docblock' => '**
     * Check whether validation process has generated any messages
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 260,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 260,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 260,
          'last-line' => 266,
          'char' => 19,
        ),
        38 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'update',
          'docblock' => '**
     * Updates a model instance. If the instance doesn\'t exist in the
     * persistence it will throw an exception. Returning true on success or
     * false otherwise.
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
                'file' => '/app/phalcon/Mvc/ModelInterface.zep',
                'line' => 267,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ModelInterface.zep',
            'line' => 267,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/ModelInterface.zep',
          'line' => 267,
          'last-line' => 268,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/ModelInterface.zep',
      'line' => 268,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/ModelInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);