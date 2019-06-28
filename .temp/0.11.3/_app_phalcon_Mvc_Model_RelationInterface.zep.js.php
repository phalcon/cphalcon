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
    'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\RelationInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Relation
 *',
    'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'RelationInterface',
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
          'name' => 'getFields',
          'docblock' => '**
     * Returns the fields
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
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
          'name' => 'getForeignKey',
          'docblock' => '**
     * Returns the foreign key configuration
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 32,
          'last-line' => 38,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIntermediateFields',
          'docblock' => '**
     * Gets the intermediate fields for has-*-through relations
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 39,
          'last-line' => 43,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIntermediateModel',
          'docblock' => '**
     * Gets the intermediate model for has-*-through relations
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
                'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
                'line' => 44,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
            'line' => 44,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 44,
          'last-line' => 50,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIntermediateReferencedFields',
          'docblock' => '**
     * Gets the intermediate referenced fields for has-*-through relations
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 51,
          'last-line' => 56,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOption',
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
              'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
              'line' => 57,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Returns an option by the specified name
     * If the option doesn\'t exist null is returned
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 57,
          'last-line' => 61,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOptions',
          'docblock' => '**
     * Returns the options
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
                'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
                'line' => 62,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
            'line' => 62,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 62,
          'last-line' => 68,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParams',
          'docblock' => '**
     * Returns parameters that must be always used when the related records are obtained
     *
     * @return array
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 69,
          'last-line' => 75,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReferencedFields',
          'docblock' => '**
     * Returns the referenced fields
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReferencedModel',
          'docblock' => '**
     * Returns the referenced model
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
                'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
                'line' => 81,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
            'line' => 81,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 81,
          'last-line' => 85,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'docblock' => '**
     * Returns the relations type
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
                'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
                'line' => 86,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
            'line' => 86,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 86,
          'last-line' => 90,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isForeignKey',
          'docblock' => '**
     * Check whether the relation act as a foreign key
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
                'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
                'line' => 91,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
            'line' => 91,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isReusable',
          'docblock' => '**
     * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
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
                'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
                'line' => 96,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
            'line' => 96,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 96,
          'last-line' => 100,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isThrough',
          'docblock' => '**
     * Check whether the relation is a \'many-to-many\' relation or not
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
                'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
                'line' => 101,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
            'line' => 101,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 101,
          'last-line' => 108,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setIntermediateRelation',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'intermediateFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
              'line' => 109,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'intermediateModel',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
              'line' => 109,
              'char' => 94,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'intermediateReferencedFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
              'line' => 109,
              'char' => 128,
            ),
          ),
          'docblock' => '**
     * Sets the intermediate model dat for has-*-through relations
     *
     * @param string|array intermediateFields
     * @param string|array intermediateReferencedFields
     *',
          'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
          'line' => 109,
          'last-line' => 110,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
      'line' => 110,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/RelationInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);