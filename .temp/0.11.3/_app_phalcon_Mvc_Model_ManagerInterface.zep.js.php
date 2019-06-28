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
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
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
        'name' => 'Phalcon\\Db\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
        'line' => 13,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\BehaviorInterface',
        'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
        'line' => 15,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\RelationInterface',
        'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
        'line' => 16,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\Query\\BuilderInterface',
        'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
        'line' => 17,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\QueryInterface',
        'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
        'line' => 18,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 24,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\ManagerInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Manager
 *',
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 25,
    'char' => 9,
  ),
  9 => 
  array (
    'type' => 'interface',
    'name' => 'ManagerInterface',
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
          'name' => 'addBehavior',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 30,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 30,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'behavior',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'BehaviorInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 30,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 30,
              'char' => 85,
            ),
          ),
          'docblock' => '**
     * Binds a behavior to a model
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 30,
            'char' => 94,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 30,
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
          'name' => 'addBelongsTo',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 39,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 39,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 39,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedModel',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 39,
              'char' => 89,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 39,
              'char' => 107,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 39,
                'char' => 123,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 39,
              'char' => 123,
            ),
          ),
          'docblock' => '**
     * Setup a relation reverse 1-1  between two models
     *
     * @param    mixed  fields
     * @param    mixed  referencedFields
     * @param    array  options
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 39,
                  'char' => 147,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 39,
                'char' => 147,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 39,
            'char' => 147,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 39,
          'last-line' => 47,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addHasMany',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 48,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 48,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 48,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedModel',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 48,
              'char' => 87,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 48,
              'char' => 105,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 48,
                'char' => 121,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 48,
              'char' => 121,
            ),
          ),
          'docblock' => '**
     * Setup a relation 1-n between two models
     *
     * @param    mixed  fields
     * @param    mixed  referencedFields
     * @param    array  options
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 48,
                  'char' => 145,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 48,
                'char' => 145,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 48,
            'char' => 145,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 48,
          'last-line' => 56,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addHasOne',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 57,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 57,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 57,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedModel',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 57,
              'char' => 86,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 57,
              'char' => 104,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 57,
                'char' => 120,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 57,
              'char' => 120,
            ),
          ),
          'docblock' => '**
     * Setup a 1-1 relation between two models
     *
     * @param    mixed  fields
     * @param    mixed  referencedFields
     * @param    array  options
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 57,
                  'char' => 144,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 57,
                'char' => 144,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 57,
            'char' => 144,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 57,
          'last-line' => 67,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addHasManyToMany',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 68,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 68,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 68,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'intermediateModel',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 68,
              'char' => 99,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'intermediateFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 69,
              'char' => 31,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'intermediateReferencedFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 69,
              'char' => 65,
            ),
            5 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedModel',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 69,
              'char' => 90,
            ),
            6 => 
            array (
              'type' => 'parameter',
              'name' => 'referencedFields',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 69,
              'char' => 112,
            ),
            7 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 69,
                'char' => 132,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 69,
              'char' => 132,
            ),
          ),
          'docblock' => '**
     * Setups a relation n-m between two models
     *
     * @param    string fields
     * @param    string intermediateFields
     * @param    string intermediateReferencedFields
     * @param    string referencedFields
     * @param   array options
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 69,
                  'char' => 156,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 69,
                'char' => 156,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 69,
            'char' => 156,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 68,
          'last-line' => 75,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createBuilder',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 76,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 76,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Creates a Phalcon\\Mvc\\Model\\Query\\Builder
     *
     * @param string $params
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 76,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 76,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 76,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createQuery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'phql',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 81,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Creates a Phalcon\\Mvc\\Model\\Query without execute it
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 81,
                  'char' => 66,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 81,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 81,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 81,
          'last-line' => 87,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'executeQuery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'phql',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 88,
              'char' => 46,
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 88,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 88,
              'char' => 71,
            ),
          ),
          'docblock' => '**
     * Creates a Phalcon\\Mvc\\Model\\Query and execute it
     *
     * @param array $placeholders
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 88,
                  'char' => 92,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 88,
                'char' => 92,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 88,
            'char' => 92,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 88,
          'last-line' => 92,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'existsBelongsTo',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 93,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelRelation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 93,
              'char' => 77,
            ),
          ),
          'docblock' => '**
     * Checks whether a model has a belongsTo relation with another model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 93,
                'char' => 86,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 93,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 93,
          'last-line' => 97,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'existsHasMany',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 98,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelRelation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 98,
              'char' => 75,
            ),
          ),
          'docblock' => '**
     * Checks whether a model has a hasMany relation with another model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 98,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 98,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 98,
          'last-line' => 102,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'existsHasOne',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 103,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelRelation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 103,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Checks whether a model has a hasOne relation with another model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 103,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 103,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 103,
          'last-line' => 107,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'existsHasManyToMany',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 108,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelRelation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 108,
              'char' => 81,
            ),
          ),
          'docblock' => '**
     * Checks whether a model has a hasManyToMany relation with another model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 108,
                'char' => 90,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 108,
            'char' => 90,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 108,
          'last-line' => 112,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBelongsTo',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 113,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 113,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Gets belongsTo relations defined on a model
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 113,
                  'char' => 83,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 113,
                'char' => 83,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 113,
                'char' => 90,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 113,
            'char' => 90,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 113,
          'last-line' => 123,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBelongsToRecords',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 124,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelRelation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 124,
              'char' => 81,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 124,
                'char' => 105,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 124,
              'char' => 106,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 124,
                'char' => 125,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 124,
              'char' => 125,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 124,
                'char' => 147,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 124,
              'char' => 147,
            ),
          ),
          'docblock' => '**
     * Gets belongsTo related records from a model
     *
     * @param string            $modelName
     * @param string            $modelRelation
     * @param array|string|null $parameters
     * @param ModelInterface    $record
     * @param string|null       $method
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 124,
                  'char' => 173,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 124,
                'char' => 173,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 124,
                'char' => 179,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 124,
            'char' => 179,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 124,
          'last-line' => 128,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHasMany',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 129,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 129,
              'char' => 54,
            ),
          ),
          'docblock' => '**
     * Gets hasMany relations defined on a model
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 129,
                  'char' => 81,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 129,
                'char' => 81,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 129,
                'char' => 88,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 129,
            'char' => 88,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 129,
          'last-line' => 139,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHasManyRecords',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 140,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelRelation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 140,
              'char' => 79,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 140,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 140,
              'char' => 104,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 140,
                'char' => 123,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 140,
              'char' => 123,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 140,
                'char' => 145,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 140,
              'char' => 145,
            ),
          ),
          'docblock' => '**
     * Gets hasMany related records from a model
     *
     * @param string            $modelName
     * @param string            $modelRelation
     * @param array|string|null $parameters
     * @param ModelInterface    $record
     * @param string|null       $method
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 140,
                  'char' => 171,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 140,
                'char' => 171,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 140,
                'char' => 177,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 140,
            'char' => 177,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 140,
          'last-line' => 144,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHasManyToMany',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 145,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 145,
              'char' => 60,
            ),
          ),
          'docblock' => '**
     * Gets hasManyToMany relations defined on a model
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 145,
                  'char' => 87,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 145,
                'char' => 87,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 145,
                'char' => 94,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 145,
            'char' => 94,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 145,
          'last-line' => 149,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHasOne',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 150,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 150,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Gets hasOne relations defined on a model
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 150,
                  'char' => 80,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 150,
                'char' => 80,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 150,
                'char' => 87,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 150,
            'char' => 87,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 150,
          'last-line' => 154,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHasOneAndHasMany',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 155,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 155,
              'char' => 63,
            ),
          ),
          'docblock' => '**
     * Gets hasOne relations defined on a model
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 155,
                  'char' => 89,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 155,
                'char' => 89,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 155,
            'char' => 89,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 155,
          'last-line' => 165,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHasOneRecords',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 166,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'modelRelation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 166,
              'char' => 78,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 166,
                'char' => 102,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 166,
              'char' => 103,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 166,
                'char' => 122,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 166,
              'char' => 122,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 166,
                'char' => 144,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 166,
              'char' => 144,
            ),
          ),
          'docblock' => '**
     * Gets belongsTo related records from a model
     *
     * @param string            $modelName
     * @param string            $modelRelation
     * @param array|string|null $parameters
     * @param ModelInterface    $record
     * @param string|null       $method
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 166,
                  'char' => 166,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 166,
                'char' => 166,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 166,
                'char' => 172,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 166,
            'char' => 172,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 166,
          'last-line' => 170,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLastInitialized',
          'docblock' => '**
     * Get last initialized model
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 171,
                  'char' => 61,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 171,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 171,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 171,
          'last-line' => 175,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLastQuery',
          'docblock' => '**
     * Returns the last query created or executed in the models manager
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 176,
                  'char' => 55,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 176,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 176,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 176,
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
          'name' => 'getModelSchema',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 181,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 181,
              'char' => 58,
            ),
          ),
          'docblock' => '**
     * Returns the mapped schema for a model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 181,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 181,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
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
          'name' => 'getModelSource',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 186,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 186,
              'char' => 58,
            ),
          ),
          'docblock' => '**
     * Returns the mapped source for a model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 186,
                'char' => 69,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 186,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 186,
          'last-line' => 190,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReadConnection',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 191,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 191,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Returns the connection to read data related to a model
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 191,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 191,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 191,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 191,
          'last-line' => 195,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReadConnectionService',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 196,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 196,
              'char' => 68,
            ),
          ),
          'docblock' => '**
     * Returns the connection service name used to read data related to a model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 196,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 196,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 196,
          'last-line' => 200,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRelationByAlias',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 201,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'alias',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 201,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Returns a relation by its alias
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
                  'value' => 'Relation',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 201,
                  'char' => 88,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 201,
                'char' => 88,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 201,
                'char' => 94,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 201,
            'char' => 94,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 201,
          'last-line' => 207,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRelationRecords',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'relation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'RelationInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 208,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 208,
              'char' => 68,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 208,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 208,
              'char' => 93,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 208,
                'char' => 116,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 208,
              'char' => 116,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 208,
                'char' => 138,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 208,
              'char' => 138,
            ),
          ),
          'docblock' => '**
     * Helper method to query records based on a relation definition
     *
     * @return \\Phalcon\\Mvc\\Model\\Resultset\\Simple|Phalcon\\Mvc\\Model\\Resultset\\Simple|int|false
     *',
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 208,
          'last-line' => 212,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRelations',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 213,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Query all the relationships defined on a model
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 213,
                  'char' => 77,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 213,
                'char' => 77,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 213,
            'char' => 77,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 213,
          'last-line' => 217,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRelationsBetween',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'first',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 218,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'second',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 218,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Query the relations between two models
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
                  'value' => 'RelationInterface',
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 218,
                  'char' => 97,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 218,
                'char' => 97,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 218,
                'char' => 103,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 218,
            'char' => 103,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 218,
          'last-line' => 222,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getWriteConnection',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 223,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 223,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Returns the connection to write data related to a model
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 223,
                  'char' => 85,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 223,
                'char' => 85,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 223,
            'char' => 85,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 223,
          'last-line' => 227,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getWriteConnectionService',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 228,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 228,
              'char' => 69,
            ),
          ),
          'docblock' => '**
     * Returns the connection service name used to write data related to a model
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 228,
                'char' => 80,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 228,
            'char' => 80,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 228,
          'last-line' => 232,
          'char' => 19,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'load',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'modelName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 233,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Loads a model throwing an exception if it doesn\'t exist
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
                  'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                  'line' => 233,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 233,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 233,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 233,
          'last-line' => 237,
          'char' => 19,
        ),
        33 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'initialize',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 238,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 238,
              'char' => 54,
            ),
          ),
          'docblock' => '**
     * Initializes a model in the model manager
     *',
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 238,
          'last-line' => 242,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isInitialized',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 243,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Check of a model is already initialized
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 243,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 243,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 243,
          'last-line' => 247,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isKeepingSnapshots',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 248,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 248,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Checks if a model is keeping snapshots for the queried records
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 248,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 248,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 248,
          'last-line' => 252,
          'char' => 19,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUsingDynamicUpdate',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 253,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 253,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Checks if a model is using dynamic update instead of all-field update
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 253,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 253,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 253,
          'last-line' => 264,
          'char' => 19,
        ),
        37 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'isVisibleModelProperty',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 265,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 265,
              'char' => 72,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'property',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 265,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Check whether a model property is declared as public.
     *
     * ```php
     * $isPublic = $manager->isVisibleModelProperty(
     *     new Robots(),
     *     "name"
     * );
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 265,
                'char' => 98,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 265,
            'char' => 98,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 265,
          'last-line' => 269,
          'char' => 25,
        ),
        38 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'keepSnapshots',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 270,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 270,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'keepSnapshots',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 270,
              'char' => 77,
            ),
          ),
          'docblock' => '**
     * Sets if a model must keep snapshots
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 270,
            'char' => 86,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 270,
          'last-line' => 279,
          'char' => 19,
        ),
        39 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'missingMethod',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 280,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 280,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'eventName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 280,
              'char' => 76,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 280,
              'char' => 82,
            ),
          ),
          'docblock' => '**
     * Dispatch an event to the listeners and behaviors
     * This method expects that the endpoint listeners/behaviors returns true
     * meaning that a least one is implemented
     *
     * @param array data
     * @return bool
     *',
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 280,
          'last-line' => 285,
          'char' => 19,
        ),
        40 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notifyEvent',
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
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 286,
              'char' => 50,
            ),
            1 => 
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 286,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 286,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Receives events generated in the models and dispatches them to an events-manager if available
     * Notify the behaviors that are listening in the model
     *',
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 286,
          'last-line' => 290,
          'char' => 19,
        ),
        41 => 
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
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 291,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 291,
              'char' => 64,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 291,
              'char' => 91,
            ),
          ),
          'docblock' => '**
     * Sets both write and read connection service for a model
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 291,
            'char' => 100,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 291,
          'last-line' => 295,
          'char' => 19,
        ),
        42 => 
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
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 296,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 296,
              'char' => 68,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 296,
              'char' => 95,
            ),
          ),
          'docblock' => '**
     * Sets read connection service for a model
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 296,
            'char' => 104,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 296,
          'last-line' => 300,
          'char' => 19,
        ),
        43 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setModelSchema',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 301,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 301,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'schema',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 301,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Sets the mapped schema for a model
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 301,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 301,
          'last-line' => 305,
          'char' => 19,
        ),
        44 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setModelSource',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 306,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 306,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'source',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 306,
              'char' => 74,
            ),
          ),
          'docblock' => '**
     * Sets the mapped source for a model
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 306,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 306,
          'last-line' => 310,
          'char' => 19,
        ),
        45 => 
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
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 311,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 311,
              'char' => 69,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 311,
              'char' => 96,
            ),
          ),
          'docblock' => '**
     * Sets write connection service for a model
     *',
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 311,
          'last-line' => 315,
          'char' => 19,
        ),
        46 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useDynamicUpdate',
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
                'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
                'line' => 316,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 316,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'dynamicUpdate',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
              'line' => 316,
              'char' => 80,
            ),
          ),
          'docblock' => '**
     * Sets if a model must use dynamic update instead of the all-field update
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
            'line' => 316,
            'char' => 89,
          ),
          'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
          'line' => 316,
          'last-line' => 317,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
      'line' => 317,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/ManagerInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);