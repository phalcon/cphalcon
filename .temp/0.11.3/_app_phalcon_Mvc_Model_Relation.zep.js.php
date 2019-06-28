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
    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\RelationInterface',
        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
        'line' => 13,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Relation
 *
 * This class represents a relationship between two models
 *',
    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Relation',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RelationInterface',
        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
        'line' => 21,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'fields',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 32,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'intermediateFields',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 33,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'intermediateModel',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 34,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'intermediateReferencedFields',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 35,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 36,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'referencedFields',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 37,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'referencedModel',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 38,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 45,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 46,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedModel',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 46,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'fields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 46,
              'char' => 78,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 46,
              'char' => 100,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 46,
                'char' => 120,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 46,
              'char' => 120,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 48,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 48,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'referencedModel',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'referencedModel',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 49,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 49,
                  'char' => 52,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'fields',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fields',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 50,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 50,
                  'char' => 34,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'referencedFields',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'referencedFields',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 51,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 51,
                  'char' => 54,
                ),
                4 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 52,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 52,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 53,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Relation constructor
     *
     * @param string|array fields
     * @param string|array referencedFields
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 47,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 46,
          'last-line' => 59,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFields',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 62,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'fields',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 62,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 62,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 63,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the fields
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 60,
          'last-line' => 69,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getForeignKey',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 72,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'foreignKey',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 72,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 74,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 74,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 74,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 74,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 74,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 76,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'foreignKey',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 76,
                  'char' => 50,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 76,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'foreignKey',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 76,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 76,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 76,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'foreignKey',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 77,
                    'char' => 27,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'foreignKey',
                        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                        'line' => 78,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 79,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 80,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 82,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 82,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the foreign key configuration
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 70,
          'last-line' => 89,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIntermediateFields',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 92,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'intermediateFields',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 92,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 92,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 93,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the intermediate fields for has-*-through relations
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 90,
          'last-line' => 97,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIntermediateModel',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 100,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'intermediateModel',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 100,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 100,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 101,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 99,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 99,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 98,
          'last-line' => 107,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getIntermediateReferencedFields',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 110,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'intermediateReferencedFields',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 110,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 110,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 111,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the intermediate referenced fields for has-*-through relations
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 108,
          'last-line' => 116,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 117,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'option',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 119,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 121,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'option',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 121,
                    'char' => 47,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                        'line' => 121,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                        'line' => 121,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 121,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 121,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 121,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 121,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 121,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 122,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 123,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 125,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'option',
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 125,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 126,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an option by the specified name
     * If the option doesn\'t exist null is returned
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 117,
          'last-line' => 130,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOptions',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 133,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'options',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 133,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 133,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 134,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 132,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 132,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 131,
          'last-line' => 140,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParams',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 143,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 143,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 145,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 145,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 145,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 145,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 145,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 147,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 147,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 147,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 147,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 147,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 147,
                'char' => 42,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 148,
                    'char' => 23,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                        'line' => 149,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 150,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 151,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 153,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 153,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 154,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns parameters that must be always used when the related records are obtained
     *
     * @return array
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 141,
          'last-line' => 158,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 161,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'type',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 161,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 161,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 162,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the relation type
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
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 160,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 160,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 159,
          'last-line' => 168,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReferencedFields',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 171,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'referencedFields',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 171,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 171,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 172,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the referenced fields
     *
     * @return string|array
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 169,
          'last-line' => 176,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReferencedModel',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 179,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'referencedModel',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 179,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 179,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 180,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 178,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 178,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 177,
          'last-line' => 184,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isForeignKey',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'foreignKey',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 187,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 189,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'foreignKey',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 189,
                    'char' => 57,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                        'line' => 189,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                        'line' => 189,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 189,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'foreignKey',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 189,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 189,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 189,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 189,
                'char' => 57,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 190,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 191,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 193,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'bool',
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'foreignKey',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 193,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 193,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 194,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 186,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 186,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 185,
          'last-line' => 198,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 201,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 203,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'type',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 203,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 203,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 203,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 203,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 205,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 205,
                    'char' => 22,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 205,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'HAS_ONE_THROUGH',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 205,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 205,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 205,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 205,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 205,
                      'char' => 79,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'HAS_MANY_THROUGH',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 205,
                      'char' => 79,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 205,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 205,
                  'char' => 79,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 205,
                'char' => 79,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 206,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 200,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 200,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 199,
          'last-line' => 210,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isReusable',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 213,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'reusable',
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 213,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 215,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 215,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 215,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 215,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 215,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 217,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'reusable',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 217,
                    'char' => 47,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 217,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'reusable',
                      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                      'line' => 217,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 217,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 217,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 217,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 218,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 219,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 221,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'reusable',
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 221,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 222,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                'line' => 212,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 212,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 211,
          'last-line' => 229,
          'char' => 19,
        ),
        15 => 
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
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 230,
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
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 230,
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
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 230,
              'char' => 128,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'intermediateFields',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'intermediateFields',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 232,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 232,
                  'char' => 58,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'intermediateModel',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'intermediateModel',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 233,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 233,
                  'char' => 56,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'intermediateReferencedFields',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'intermediateReferencedFields',
                    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                    'line' => 234,
                    'char' => 78,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Relation.zep',
                  'line' => 234,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Relation.zep',
              'line' => 235,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the intermediate model data for has-*-through relations
     *
     * @param string|array intermediateFields
     * @param string       intermediateReferencedFields
     *',
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 230,
          'last-line' => 236,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'ACTION_CASCADE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 22,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 23,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'ACTION_RESTRICT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 23,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 24,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'BELONGS_TO',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 24,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 25,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'HAS_MANY',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 25,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 26,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'HAS_MANY_THROUGH',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 26,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 27,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'HAS_ONE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 27,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 28,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'HAS_ONE_THROUGH',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 28,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 29,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'NO_ACTION',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Model/Relation.zep',
            'line' => 29,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/Relation.zep',
          'line' => 31,
          'char' => 13,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Relation.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Relation.zep',
    'line' => 20,
    'char' => 5,
  ),
);