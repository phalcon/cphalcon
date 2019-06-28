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
    'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\CriteriaInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Criteria
 *',
    'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'CriteriaInterface',
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
          'name' => 'andWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 28,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 28,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 28,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 28,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 28,
              'char' => 85,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current conditions using an AND operator
     *
     * @param array bindParams
     * @param array bindTypes
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 28,
                  'char' => 109,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 28,
                'char' => 109,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 28,
            'char' => 109,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 28,
          'last-line' => 39,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'betweenWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 40,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 40,
              'char' => 55,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 40,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Appends a BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->betweenWhere("price", 100.25, 200.50);
     *```
     *
     * @param mixed minimum
     * @param mixed maximum
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 40,
                  'char' => 88,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 40,
                'char' => 88,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 40,
            'char' => 88,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 40,
          'last-line' => 45,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bind',
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
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 46,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Sets the bound parameters in the criteria
     * This method replaces all previously set bound parameters
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 46,
                  'char' => 67,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 46,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 46,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 46,
          'last-line' => 51,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bindTypes',
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
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 52,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Sets the bind types in the criteria
     * This method replaces all previously set bound parameters
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 52,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 52,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 52,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 52,
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
          'name' => 'cache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cache',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 58,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Sets the cache options in the criteria
     * This method replaces all previously set cache options
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 58,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 58,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 58,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
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
          'name' => 'conditions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 63,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Adds the conditions parameter to the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 63,
                  'char' => 74,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 63,
                'char' => 74,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 63,
            'char' => 74,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
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
          'name' => 'distinct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'distinct',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 68,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Sets SELECT DISTINCT / SELECT ALL flag
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 68,
                  'char' => 67,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 68,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 68,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 68,
          'last-line' => 72,
          'char' => 20,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'execute',
          'docblock' => '**
     * Executes a find using the parameters built with the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 73,
                  'char' => 54,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 73,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 73,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
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
          'name' => 'forUpdate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'forUpdate',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 78,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 78,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets the "for_update" parameter to the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 78,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 78,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 78,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 78,
          'last-line' => 84,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumns',
          'docblock' => '**
     * Returns the columns to be queried
     *
     * @return string|array|null
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
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 85,
                'char' => 44,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 85,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 85,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 85,
          'last-line' => 89,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConditions',
          'docblock' => '**
     * Returns the conditions parameter in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 90,
                'char' => 47,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 90,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 90,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 90,
          'last-line' => 94,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getGroupBy',
          'docblock' => '**
     * Returns the group clause in the criteria
     *',
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 95,
          'last-line' => 99,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHaving',
          'docblock' => '**
     * Returns the having clause in the criteria
     *',
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 100,
          'last-line' => 106,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLimit',
          'docblock' => '**
     * Returns the limit parameter in the criteria, which will be an integer if
     * limit was set without an offset, an array with \'number\' and \'offset\' keys
     * if an offset was set with the limit, or null if limit has not been set.
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
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 107,
                'char' => 42,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 107,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 107,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 107,
          'last-line' => 111,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModelName',
          'docblock' => '**
     * Returns an internal model name on which the criteria will be applied
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
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 112,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 112,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 112,
          'last-line' => 116,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOrderBy',
          'docblock' => '**
     * Returns the order parameter in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 117,
                'char' => 44,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 117,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 117,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 117,
          'last-line' => 121,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParams',
          'docblock' => '**
     * Returns all the parameters defined in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 122,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 122,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 122,
          'last-line' => 126,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getWhere',
          'docblock' => '**
     * Returns the conditions parameter in the criteria
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
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 127,
                'char' => 42,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 127,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 127,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 127,
          'last-line' => 131,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'groupBy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'group',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 132,
              'char' => 38,
            ),
          ),
          'docblock' => '**
     * Adds the group-by clause to the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 132,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 132,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 132,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 132,
          'last-line' => 136,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'having',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'having',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 137,
              'char' => 38,
            ),
          ),
          'docblock' => '**
     * Adds the having clause to the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 137,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 137,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 137,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 137,
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
          'name' => 'innerJoin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 159,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 159,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 159,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 159,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 159,
              'char' => 85,
            ),
          ),
          'docblock' => '**
     * Adds an INNER join to the query
     *
     *```php
     * $criteria->innerJoin(
     *     Robots::class
     * );
     *
     * $criteria->innerJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id"
     * );
     *
     * $criteria->innerJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 159,
                  'char' => 109,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 159,
                'char' => 109,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 159,
            'char' => 109,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 159,
          'last-line' => 167,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 168,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 168,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Appends an IN condition to the current conditions
     *
     *```php
     * $criteria->inWhere("id", [1, 2, 3]);
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 168,
                  'char' => 80,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 168,
                'char' => 80,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 168,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 168,
          'last-line' => 180,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'leftJoin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 181,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 181,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 181,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 181,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 181,
              'char' => 84,
            ),
          ),
          'docblock' => '**
     * Adds a LEFT join to the query
     *
     *```php
     * $criteria->leftJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 181,
                  'char' => 108,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 181,
                'char' => 108,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 181,
            'char' => 108,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 181,
          'last-line' => 185,
          'char' => 19,
        ),
        23 => 
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
              'name' => 'limit',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 186,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 186,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 186,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets the limit parameter to the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 186,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 186,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 186,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 186,
          'last-line' => 197,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notBetweenWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 198,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'minimum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 198,
              'char' => 58,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'maximum',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 198,
              'char' => 67,
            ),
          ),
          'docblock' => '**
     * Appends a NOT BETWEEN condition to the current conditions
     *
     *```php
     * $criteria->notBetweenWhere("price", 100.25, 200.50);
     *```
     *
     * @param mixed minimum
     * @param mixed maximum
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 198,
                  'char' => 91,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 198,
                'char' => 91,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 198,
            'char' => 91,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 198,
          'last-line' => 206,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notInWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expr',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 207,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 207,
              'char' => 59,
            ),
          ),
          'docblock' => '**
     * Appends a NOT IN condition to the current conditions
     *
     *```php
     * $criteria->notInWhere("id", [1, 2, 3]);
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 207,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 207,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 207,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 207,
          'last-line' => 211,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'orderBy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'orderColumns',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 212,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Adds the order-by parameter to the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 212,
                  'char' => 73,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 212,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 212,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 212,
          'last-line' => 219,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'orWhere',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 220,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 220,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 220,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 220,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 220,
              'char' => 84,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current conditions using an OR operator
     *
     * @param array bindParams
     * @param array bindTypes
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 220,
                  'char' => 108,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 220,
                'char' => 108,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 220,
            'char' => 108,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 220,
          'last-line' => 232,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rightJoin',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 233,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 233,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 233,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 233,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 233,
              'char' => 77,
            ),
          ),
          'docblock' => '**
     * Adds a RIGHT join to the query
     *
     *```php
     * $criteria->rightJoin(
     *     Robots::class,
     *     "r.id = RobotsParts.robots_id",
     *     "r"
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
                  'value' => 'CriteriaInterface',
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 233,
                  'char' => 101,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 233,
                'char' => 101,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 233,
            'char' => 101,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 233,
          'last-line' => 237,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setModelName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'modelName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 238,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Set a model on which the query will be executed
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 238,
                  'char' => 75,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 238,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 238,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 238,
          'last-line' => 242,
          'char' => 19,
        ),
        30 => 
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
              'name' => 'sharedLock',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 243,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 243,
              'char' => 54,
            ),
          ),
          'docblock' => '**
     * Sets the "shared_lock" parameter to the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 243,
                  'char' => 78,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 243,
                'char' => 78,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 243,
            'char' => 78,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 243,
          'last-line' => 247,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'where',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
              'line' => 248,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets the conditions parameter in the criteria
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
                  'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                  'line' => 248,
                  'char' => 69,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
                'line' => 248,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
            'line' => 248,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
          'line' => 248,
          'last-line' => 249,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
      'line' => 249,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/CriteriaInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);