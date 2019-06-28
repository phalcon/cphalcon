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
    'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Query',
    'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\QueryInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
        'line' => 13,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Query\\BuilderInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Query\\Builder
 *',
    'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'BuilderInterface',
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
          'name' => 'addFrom',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 28,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 28,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 28,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Add a model to take part of the query
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 28,
                  'char' => 85,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 28,
                'char' => 85,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 28,
            'char' => 85,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 28,
          'last-line' => 32,
          'char' => 19,
        ),
        1 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 33,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 33,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 33,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 33,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 33,
              'char' => 92,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current conditions using a AND operator
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 33,
                  'char' => 115,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 33,
                'char' => 115,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 33,
            'char' => 115,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 33,
          'last-line' => 40,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 41,
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 41,
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 41,
              'char' => 64,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 41,
                  'char' => 115,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 41,
                  'char' => 115,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 41,
                'char' => 115,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 41,
              'char' => 115,
            ),
          ),
          'docblock' => '**
     * Appends a BETWEEN condition to the current conditions
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 41,
                  'char' => 138,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 41,
                'char' => 138,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 41,
            'char' => 138,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 41,
          'last-line' => 47,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'columns',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'columns',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 48,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Sets the columns to be queried
     *
     * @param string|array columns
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 48,
                  'char' => 59,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 48,
                'char' => 59,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 48,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 48,
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 58,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Sets SELECT DISTINCT / SELECT ALL flag
     *
     *```php
     * $builder->distinct("status");
     * $builder->distinct(null);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 58,
                  'char' => 65,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 58,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 58,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 58,
          'last-line' => 66,
          'char' => 19,
        ),
        5 => 
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
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 67,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Sets a FOR UPDATE clause
     *
     *```php
     * $builder->forUpdate(true);
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 67,
                  'char' => 68,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 67,
                'char' => 68,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 67,
            'char' => 68,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 67,
          'last-line' => 73,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'from',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'models',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 74,
              'char' => 32,
            ),
          ),
          'docblock' => '**
     * Sets the models who makes part of the query
     *
     * @param string|array models
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 74,
                  'char' => 55,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 74,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 74,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 74,
          'last-line' => 78,
          'char' => 19,
        ),
        7 => 
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 79,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 79,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 79,
          'last-line' => 83,
          'char' => 19,
        ),
        8 => 
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 84,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 84,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 84,
          'last-line' => 90,
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
     * Return the columns to be queried
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDistinct',
          'docblock' => '**
     * Returns SELECT DISTINCT / SELECT ALL flag
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 96,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 96,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 96,
          'last-line' => 102,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFrom',
          'docblock' => '**
     * Return the models who makes part of the query
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 103,
          'last-line' => 107,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getGroupBy',
          'docblock' => '**
     * Returns the GROUP BY clause
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 108,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 108,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 108,
          'last-line' => 112,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHaving',
          'docblock' => '**
     * Returns the HAVING condition clause
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 113,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 113,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 113,
          'last-line' => 117,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getJoins',
          'docblock' => '**
     * Return join parts of the query
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 118,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 118,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 118,
          'last-line' => 124,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLimit',
          'docblock' => '**
     * Returns the current LIMIT clause
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 125,
          'last-line' => 129,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOffset',
          'docblock' => '**
     * Returns the current OFFSET clause
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 130,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 130,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 130,
          'last-line' => 136,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOrderBy',
          'docblock' => '**
     * Return the set ORDER BY clause
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 137,
          'last-line' => 141,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPhql',
          'docblock' => '**
     * Returns a PHQL statement built based on the builder parameters
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 142,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 142,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 142,
          'last-line' => 146,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getQuery',
          'docblock' => '**
     * Returns the query built
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
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 147,
                  'char' => 51,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 147,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 147,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 147,
          'last-line' => 153,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getWhere',
          'docblock' => '**
     * Return the conditions for the query
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 154,
          'last-line' => 160,
          'char' => 19,
        ),
        21 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 161,
              'char' => 38,
            ),
          ),
          'docblock' => '**
     * Sets a GROUP BY clause
     *
     * @param string|array group
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 161,
                  'char' => 61,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 161,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 161,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 161,
          'last-line' => 165,
          'char' => 19,
        ),
        22 => 
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
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 166,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets a HAVING condition clause
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 166,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 166,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 166,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 166,
          'last-line' => 170,
          'char' => 19,
        ),
        23 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 171,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 171,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 171,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 171,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 171,
              'char' => 90,
            ),
          ),
          'docblock' => '**
     * Adds an INNER join to the query
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 171,
                  'char' => 113,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 171,
                'char' => 113,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 171,
            'char' => 113,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 171,
          'last-line' => 175,
          'char' => 19,
        ),
        24 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 176,
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 176,
              'char' => 56,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 176,
                  'char' => 107,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 176,
                  'char' => 107,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 176,
                'char' => 107,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 176,
              'char' => 107,
            ),
          ),
          'docblock' => '**
     * Appends an IN condition to the current conditions
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 176,
                  'char' => 130,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 176,
                'char' => 130,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 176,
            'char' => 130,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 176,
          'last-line' => 186,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'join',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 187,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 187,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 187,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 187,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 187,
              'char' => 85,
            ),
          ),
          'docblock' => '**
     * Adds an :type: join (by default type - INNER) to the query
     *
     * @param string model
     * @param string conditions
     * @param string alias
     * @param string type
     * @return BuilderInterface
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 187,
                  'char' => 108,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 187,
                'char' => 108,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 187,
            'char' => 108,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 187,
          'last-line' => 191,
          'char' => 19,
        ),
        26 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 192,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 192,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 192,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 192,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 192,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Adds a LEFT join to the query
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 192,
                  'char' => 112,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 192,
                'char' => 112,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 192,
            'char' => 112,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 192,
          'last-line' => 198,
          'char' => 19,
        ),
        27 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 199,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 199,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 199,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets a LIMIT clause
     *
     * @param int offset
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 199,
                  'char' => 74,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 199,
                'char' => 74,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 199,
            'char' => 74,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 199,
          'last-line' => 203,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModels',
          'docblock' => '**
     * Returns the models involved in the query
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 204,
                'char' => 43,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 204,
                'char' => 51,
              ),
              2 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 204,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 204,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 204,
          'last-line' => 211,
          'char' => 19,
        ),
        29 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 212,
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 212,
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 212,
              'char' => 67,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 212,
                  'char' => 118,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 212,
                  'char' => 118,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 212,
                'char' => 118,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 212,
              'char' => 118,
            ),
          ),
          'docblock' => '**
     * Appends a NOT BETWEEN condition to the current conditions
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 212,
                  'char' => 141,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 212,
                'char' => 141,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 212,
            'char' => 141,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 212,
          'last-line' => 216,
          'char' => 19,
        ),
        30 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 217,
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 217,
              'char' => 59,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'operator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 217,
                  'char' => 110,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'OPERATOR_AND',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 217,
                  'char' => 110,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 217,
                'char' => 110,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 217,
              'char' => 110,
            ),
          ),
          'docblock' => '**
     * Appends a NOT IN condition to the current conditions
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 217,
                  'char' => 133,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 217,
                'char' => 133,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 217,
            'char' => 133,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 217,
          'last-line' => 221,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 222,
              'char' => 38,
            ),
          ),
          'docblock' => '**
     * Sets an OFFSET clause
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 222,
                  'char' => 61,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 222,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 222,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 222,
          'last-line' => 226,
          'char' => 19,
        ),
        32 => 
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
              'name' => 'orderBy',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 227,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Sets an ORDER BY condition clause
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 227,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 227,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 227,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 227,
          'last-line' => 231,
          'char' => 19,
        ),
        33 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 232,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 232,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 232,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 232,
                'char' => 91,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 232,
              'char' => 91,
            ),
          ),
          'docblock' => '**
     * Appends a condition to the current conditions using an OR operator
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 232,
                  'char' => 114,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 232,
                'char' => 114,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 232,
            'char' => 114,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 232,
          'last-line' => 236,
          'char' => 19,
        ),
        34 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 237,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'conditions',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 237,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 237,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 237,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 237,
              'char' => 90,
            ),
          ),
          'docblock' => '**
     * Adds a RIGHT join to the query
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 237,
                  'char' => 113,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 237,
                'char' => 113,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 237,
            'char' => 113,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 237,
          'last-line' => 241,
          'char' => 19,
        ),
        35 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 242,
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 242,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 242,
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 242,
                  'char' => 95,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 242,
                'char' => 95,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 242,
            'char' => 95,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 242,
          'last-line' => 246,
          'char' => 19,
        ),
        36 => 
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
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 247,
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
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 247,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 247,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Set default bind types
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 247,
                  'char' => 93,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 247,
                'char' => 93,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 247,
            'char' => 93,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 247,
          'last-line' => 251,
          'char' => 19,
        ),
        37 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 252,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'bindParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 252,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 252,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'bindTypes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 252,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
              'line' => 252,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Sets conditions for the query
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
                  'value' => 'BuilderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                  'line' => 252,
                  'char' => 112,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
                'line' => 252,
                'char' => 112,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 252,
            'char' => 112,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 252,
          'last-line' => 253,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'OPERATOR_AND',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'and',
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 22,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 23,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'OPERATOR_OR',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'or',
            'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
            'line' => 23,
            'char' => 27,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
          'line' => 27,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
      'line' => 253,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/BuilderInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);