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
    'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData',
    'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'StrategyInterface',
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
          'name' => 'getColumnMaps',
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
                'line' => 23,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
              'line' => 23,
              'char' => 57,
            ),
            1 => 
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
                'line' => 23,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
              'line' => 23,
              'char' => 82,
            ),
          ),
          'docblock' => '**
     * Read the model\'s column map, this can\'t be inferred
     *
     * @todo Not implemented
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
                'line' => 23,
                'char' => 92,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
            'line' => 23,
            'char' => 92,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
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
          'name' => 'getMetaData',
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
                'line' => 28,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
              'line' => 28,
              'char' => 55,
            ),
            1 => 
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
                'line' => 28,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
              'line' => 28,
              'char' => 80,
            ),
          ),
          'docblock' => '**
     * The meta-data is obtained by reading the column descriptions from the database information schema
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
                'line' => 28,
                'char' => 90,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
            'line' => 28,
            'char' => 90,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
          'line' => 28,
          'last-line' => 29,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
      'line' => 29,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/StrategyInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);