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
    'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
        'line' => 14,
        'char' => 49,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaDataInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\MetaData
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
    'line' => 21,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'MetaDataInterface',
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
          'name' => 'getAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 26,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 26,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Returns table attributes names (fields)
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 26,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 26,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAutomaticCreateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 31,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 31,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Returns attributes that must be ignored from the INSERT SQL generation
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 31,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 31,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 31,
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
          'name' => 'getAutomaticUpdateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 36,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 36,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Returns attributes that must be ignored from the UPDATE SQL generation
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 36,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 36,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 36,
          'last-line' => 40,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBindTypes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 41,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 41,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Returns attributes and their bind data types
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 41,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 41,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 41,
          'last-line' => 45,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getColumnMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 46,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 46,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Returns the column map if any
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 46,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 46,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 46,
          'last-line' => 50,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultValues',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 51,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 51,
              'char' => 60,
            ),
          ),
          'docblock' => '**
     * Returns attributes (which have default values) and their default values
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 51,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 51,
            'char' => 70,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 51,
          'last-line' => 55,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDataTypes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 56,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 56,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Returns attributes and their data types
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 56,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 56,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 56,
          'last-line' => 60,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDataTypesNumeric',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 61,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 61,
              'char' => 63,
            ),
          ),
          'docblock' => '**
     * Returns attributes which types are numerical
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 61,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 61,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 61,
          'last-line' => 65,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEmptyStringAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 66,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 66,
              'char' => 68,
            ),
          ),
          'docblock' => '**
     * Returns attributes allow empty strings
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 66,
                'char' => 78,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 66,
            'char' => 78,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 66,
          'last-line' => 70,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIdentityField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 71,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 71,
              'char' => 60,
            ),
          ),
          'docblock' => '**
     * Returns the name of identity field (if one is present)
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 71,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 71,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 71,
          'last-line' => 75,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNonPrimaryKeyAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 76,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 76,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Returns an array of fields which are not part of the primary key
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 76,
                'char' => 80,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 76,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNotNullAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 81,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 81,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Returns an array of not null attributes
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 81,
                'char' => 74,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 81,
            'char' => 74,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 81,
          'last-line' => 85,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPrimaryKeyAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 86,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 86,
              'char' => 67,
            ),
          ),
          'docblock' => '**
     * Returns an array of fields which are part of the primary key
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 86,
                'char' => 77,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 86,
            'char' => 77,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 86,
          'last-line' => 90,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReverseColumnMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 91,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 91,
              'char' => 63,
            ),
          ),
          'docblock' => '**
     * Returns the reverse column map if any
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 91,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 91,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getStrategy',
          'docblock' => '**
     * Return the strategy to obtain the meta-data
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
                  'value' => 'StrategyInterface',
                  'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                  'line' => 96,
                  'char' => 57,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 96,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 96,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 96,
          'last-line' => 100,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 101,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 101,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 101,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Check if a model has certain attribute
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 101,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 101,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 101,
          'last-line' => 105,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isEmpty',
          'docblock' => '**
     * Checks if the internal meta-data container is empty
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 106,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 106,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 106,
          'last-line' => 110,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'read',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 111,
              'char' => 36,
            ),
          ),
          'docblock' => '**
     * Reads meta-data from the adapter
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 111,
                'char' => 47,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 111,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 111,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 111,
          'last-line' => 115,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'readColumnMap',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 116,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 116,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Reads the ordered/reversed column map for certain model
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 116,
                'char' => 68,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 116,
                'char' => 74,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 116,
            'char' => 74,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 116,
          'last-line' => 120,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'readColumnMapIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 121,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 121,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 121,
              'char' => 73,
            ),
          ),
          'docblock' => '**
     * Reads column-map information for certain model using a MODEL_* constant
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 121,
          'last-line' => 125,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'readMetaData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 126,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 126,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Reads meta-data for certain model
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 126,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 126,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 126,
          'last-line' => 130,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'readMetaDataIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 131,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 131,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 131,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Reads meta-data for certain model using a MODEL_* constant
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
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 131,
                'char' => 80,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 131,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 131,
          'last-line' => 135,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
          'docblock' => '**
     * Resets internal meta-data in order to regenerate it
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 136,
          'last-line' => 140,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAutomaticCreateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 141,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 141,
              'char' => 72,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 141,
              'char' => 90,
            ),
          ),
          'docblock' => '**
     * Set the attributes that must be ignored from the INSERT SQL generation
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 141,
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
          'name' => 'setAutomaticUpdateAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 146,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 146,
              'char' => 72,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 146,
              'char' => 90,
            ),
          ),
          'docblock' => '**
     * Set the attributes that must be ignored from the UPDATE SQL generation
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
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
          'name' => 'setEmptyStringAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 151,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 151,
              'char' => 68,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 151,
              'char' => 86,
            ),
          ),
          'docblock' => '**
     * Set the attributes that allow empty string values
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 151,
            'char' => 95,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 151,
          'last-line' => 155,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'writeMetaDataIndex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 156,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 156,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 156,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 156,
              'char' => 83,
            ),
          ),
          'docblock' => '**
     * Writes meta-data for certain model using a MODEL_* constant
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 156,
          'last-line' => 160,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setStrategy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'strategy',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'StrategyInterface',
                'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
                'line' => 161,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 161,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Set the meta-data extraction strategy
     *',
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 161,
          'last-line' => 165,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'write',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 166,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
              'line' => 166,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Writes meta-data to the adapter
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
            'line' => 166,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
          'line' => 166,
          'last-line' => 167,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
      'line' => 167,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaDataInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);