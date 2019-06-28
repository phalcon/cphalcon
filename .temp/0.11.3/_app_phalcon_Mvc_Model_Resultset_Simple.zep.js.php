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
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Resultset',
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
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
        'name' => 'Phalcon\\Di',
        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
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
        'name' => 'Phalcon\\Mvc\\Model',
        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
        'line' => 15,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
        'line' => 16,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Resultset',
        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
        'line' => 18,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
        'line' => 19,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
    'line' => 26,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Resultset\\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 *',
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
    'line' => 27,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Simple',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Resultset',
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
          'name' => 'columnMap',
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 30,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'model',
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 33,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'keepSnapshots',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
            'line' => 34,
            'char' => 36,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 41,
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
              'name' => 'columnMap',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 43,
              'char' => 22,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 44,
              'char' => 18,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'result',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 45,
              'char' => 15,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'cache',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 46,
                'char' => 32,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 46,
                'char' => 40,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 46,
              'char' => 40,
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
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 48,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 48,
              'char' => 5,
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
                  'property' => 'model',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'model',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 49,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 49,
                  'char' => 32,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'columnMap',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'columnMap',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 50,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 50,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 54,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'keepSnapshots',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'keepSnapshots',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 54,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 54,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 56,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'result',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 56,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 56,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 56,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 56,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 56,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Resultset\\Simple constructor
     *
     * @param array                                             columnMap
     * @param \\Phalcon\\Mvc\\ModelInterface|Phalcon\\Mvc\\Model\\Row model
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
            'line' => 48,
            'char' => 15,
          ),
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 42,
          'last-line' => 61,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'current',
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
                  'variable' => 'row',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 64,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'hydrateMode',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 64,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'columnMap',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 64,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'activeRow',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 64,
                  'char' => 51,
                ),
                4 => 
                array (
                  'variable' => 'modelName',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 64,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 66,
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
                  'variable' => 'activeRow',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 66,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeRow',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 66,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 66,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 66,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 68,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeRow',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 68,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 68,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 68,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'activeRow',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 69,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 70,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 75,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'row',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 75,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'row',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 75,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 75,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 75,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 80,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'row',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 80,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 80,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 80,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 80,
                'char' => 32,
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
                      'property' => 'activeRow',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 81,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 81,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 83,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 83,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 89,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'hydrateMode',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 89,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hydrateMode',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 89,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 89,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 89,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 94,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'columnMap',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 94,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnMap',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 94,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 94,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 94,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 99,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'hydrateMode',
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 99,
                'char' => 28,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Resultset',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 100,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'HYDRATE_RECORDS',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 100,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 100,
                    'char' => 44,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'globals_get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'orm.late_state_binding',
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 105,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 105,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 105,
                        'char' => 56,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'instanceof',
                            'left' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 106,
                                'char' => 29,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'model',
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 106,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 106,
                              'char' => 45,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'Model',
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 106,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 106,
                            'char' => 53,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'modelName',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'get_class',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'property-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                            'line' => 107,
                                            'char' => 56,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'model',
                                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                            'line' => 107,
                                            'char' => 62,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                          'line' => 107,
                                          'char' => 62,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 107,
                                        'char' => 62,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 107,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 107,
                                  'char' => 63,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 108,
                              'char' => 21,
                            ),
                          ),
                          'else_statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'modelName',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Phalcon\\\\Mvc\\\\Model',
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 109,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 109,
                                  'char' => 60,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 110,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 112,
                          'char' => 23,
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
                              'variable' => 'activeRow',
                              'expr' => 
                              array (
                                'type' => 'scall',
                                'dynamic-class' => 1,
                                'class' => 'modelName',
                                'dynamic' => 0,
                                'name' => 'cloneResultMap',
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'property-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 113,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'model',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 113,
                                        'char' => 36,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 113,
                                      'char' => 36,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 113,
                                    'char' => 36,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'row',
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 114,
                                      'char' => 28,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 114,
                                    'char' => 28,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'columnMap',
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 115,
                                      'char' => 34,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 115,
                                    'char' => 34,
                                  ),
                                  3 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'static-constant-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'Model',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 116,
                                        'char' => 54,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'DIRTY_STATE_PERSISTENT',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 116,
                                        'char' => 54,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 116,
                                      'char' => 54,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 116,
                                    'char' => 54,
                                  ),
                                  4 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'property-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 117,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'keepSnapshots',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 118,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 118,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 118,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 118,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 118,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 119,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'activeRow',
                              'expr' => 
                              array (
                                'type' => 'scall',
                                'dynamic-class' => 0,
                                'class' => 'Model',
                                'dynamic' => 0,
                                'name' => 'cloneResultMap',
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'property-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 121,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'model',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 121,
                                        'char' => 36,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 121,
                                      'char' => 36,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 121,
                                    'char' => 36,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'row',
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 122,
                                      'char' => 28,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 122,
                                    'char' => 28,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'columnMap',
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 123,
                                      'char' => 34,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 123,
                                    'char' => 34,
                                  ),
                                  3 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'static-constant-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'Model',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 124,
                                        'char' => 54,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'DIRTY_STATE_PERSISTENT',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 124,
                                        'char' => 54,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 124,
                                      'char' => 54,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 124,
                                    'char' => 54,
                                  ),
                                  4 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'property-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 125,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'keepSnapshots',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 126,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 126,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 126,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 126,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 126,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 127,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 129,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 131,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 131,
                  'char' => 19,
                ),
                1 => 
                array (
                  'type' => 'default',
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'activeRow',
                          'expr' => 
                          array (
                            'type' => 'scall',
                            'dynamic-class' => 0,
                            'class' => 'Model',
                            'dynamic' => 0,
                            'name' => 'cloneResultMapHydrate',
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'row',
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 136,
                                  'char' => 24,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 136,
                                'char' => 24,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'columnMap',
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 137,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 137,
                                'char' => 30,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'hydrateMode',
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 139,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 139,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 139,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 139,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 141,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 142,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 142,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 144,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'activeRow',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'activeRow',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 144,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 144,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 146,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'activeRow',
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 146,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 147,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns current row in the resultset
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
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 62,
                  'char' => 57,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 62,
                'char' => 57,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 62,
          'last-line' => 154,
          'char' => 25,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toArray',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'renameColumns',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 155,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 155,
              'char' => 54,
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
                  'variable' => 'result',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 157,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'records',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 157,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'record',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 157,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'renamedKey',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 157,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 157,
                  'char' => 53,
                ),
                5 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 157,
                  'char' => 60,
                ),
                6 => 
                array (
                  'variable' => 'columnMap',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 157,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 158,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'renamedRecords',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 158,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'renamed',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 158,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 164,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'records',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 164,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rows',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 164,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 164,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 164,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 166,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'records',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 166,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 166,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 166,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 166,
                'char' => 36,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 167,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'result',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 167,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 167,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 167,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 169,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 169,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'row',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 169,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 169,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 169,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 169,
                    'char' => 35,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'result',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 171,
                          'char' => 24,
                        ),
                        'name' => 'execute',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 171,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 172,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 174,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'records',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'result',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 174,
                          'char' => 34,
                        ),
                        'name' => 'fetchAll',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 174,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 174,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 176,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'row',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 176,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 176,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 177,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'rows',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'records',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 177,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 177,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 178,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 183,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'renameColumns',
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 183,
                'char' => 26,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'columnMap',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 187,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'columnMap',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 187,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 187,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 187,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 189,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnMap',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 189,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 189,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 189,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 189,
                    'char' => 42,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'records',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 190,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 191,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 193,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'renamedRecords',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 193,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 193,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 195,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'records',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 195,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 195,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 195,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 195,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'records',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 196,
                        'char' => 39,
                      ),
                      'value' => 'record',
                      'reverse' => 0,
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'renamed',
                              'expr' => 
                              array (
                                'type' => 'empty-array',
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 197,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 197,
                              'char' => 37,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 199,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'record',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 199,
                            'char' => 46,
                          ),
                          'key' => 'key',
                          'value' => 'value',
                          'reverse' => 0,
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'unlikely',
                                'left' => 
                                array (
                                  'type' => 'not',
                                  'left' => 
                                  array (
                                    'type' => 'fetch',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'renamedKey',
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 203,
                                      'char' => 71,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'columnMap',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 203,
                                        'char' => 65,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'key',
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 203,
                                        'char' => 69,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 203,
                                      'char' => 71,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 203,
                                    'char' => 71,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 203,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 203,
                                'char' => 71,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'throw',
                                  'expr' => 
                                  array (
                                    'type' => 'new',
                                    'class' => 'Exception',
                                    'dynamic' => 0,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'Column \'',
                                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                              'line' => 205,
                                              'char' => 42,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'key',
                                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                              'line' => 205,
                                              'char' => 48,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                            'line' => 205,
                                            'char' => 48,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\' is not part of the column map',
                                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                            'line' => 206,
                                            'char' => 29,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                          'line' => 206,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 206,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 206,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 207,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 209,
                              'char' => 26,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'typeof',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'renamedKey',
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 209,
                                    'char' => 47,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 209,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'array',
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 209,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 209,
                                'char' => 55,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'if',
                                  'expr' => 
                                  array (
                                    'type' => 'unlikely',
                                    'left' => 
                                    array (
                                      'type' => 'not',
                                      'left' => 
                                      array (
                                        'type' => 'fetch',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'renamedKey',
                                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                          'line' => 210,
                                          'char' => 74,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'array-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'renamedKey',
                                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                            'line' => 210,
                                            'char' => 70,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'int',
                                            'value' => '0',
                                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                            'line' => 210,
                                            'char' => 72,
                                          ),
                                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                          'line' => 210,
                                          'char' => 74,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 210,
                                        'char' => 74,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 210,
                                      'char' => 74,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 210,
                                    'char' => 74,
                                  ),
                                  'statements' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'throw',
                                      'expr' => 
                                      array (
                                        'type' => 'new',
                                        'class' => 'Exception',
                                        'dynamic' => 0,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'concat',
                                              'left' => 
                                              array (
                                                'type' => 'concat',
                                                'left' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => 'Column \'',
                                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                                  'line' => 212,
                                                  'char' => 46,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'key',
                                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                                  'line' => 212,
                                                  'char' => 52,
                                                ),
                                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                                'line' => 212,
                                                'char' => 52,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => '\' is not part of the column map',
                                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                                'line' => 213,
                                                'char' => 33,
                                              ),
                                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                              'line' => 213,
                                              'char' => 33,
                                            ),
                                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                            'line' => 213,
                                            'char' => 33,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                        'line' => 213,
                                        'char' => 34,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 214,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 215,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 217,
                              'char' => 27,
                            ),
                            2 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'renamed',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'renamedKey',
                                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                      'line' => 217,
                                      'char' => 47,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                    'line' => 217,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                  'line' => 217,
                                  'char' => 56,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 218,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 223,
                          'char' => 23,
                        ),
                        2 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'renamedRecords',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'renamed',
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 223,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 223,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 224,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 225,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 227,
                  'char' => 18,
                ),
                4 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'renamedRecords',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 227,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 228,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 230,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'records',
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 230,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 231,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a complete resultset as an array, if the resultset has a big
     * number of rows it could consume more memory than currently it does.
     * Export the resultset to an array couldn\'t be faster with a large number
     * of records
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
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 155,
          'last-line' => 235,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'serialize',
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 238,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'serializer',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 238,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 239,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 239,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 241,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Di',
                    'dynamic' => 0,
                    'name' => 'getDefault',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 241,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 241,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 243,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 243,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 243,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 243,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 243,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 243,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The dependency injector container is not valid',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 246,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 246,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 246,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 247,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 249,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'model',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 250,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 250,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'model',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 250,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 250,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 250,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'cache',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 251,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 251,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'cache',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 251,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 251,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 251,
                        'char' => 40,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'rows',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 252,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 252,
                            'char' => 34,
                          ),
                          'name' => 'toArray',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'false',
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 252,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 252,
                              'char' => 48,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 252,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 252,
                        'char' => 49,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'columnMap',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 253,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 253,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'columnMap',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 253,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 253,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 253,
                        'char' => 44,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'hydrateMode',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 254,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 254,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'hydrateMode',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 254,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 254,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 254,
                        'char' => 46,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'keepSnapshots',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 255,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 255,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'keepSnapshots',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 256,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 256,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 256,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 256,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 256,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 258,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 258,
                  'char' => 22,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'serializer',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 258,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 258,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 258,
                'char' => 39,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'serializer',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'SerializerInterface',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 259,
                          'char' => 84,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 259,
                            'char' => 62,
                          ),
                          'name' => 'getShared',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'serializer',
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 259,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 259,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 259,
                          'char' => 84,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 259,
                        'char' => 84,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 259,
                      'char' => 84,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 260,
                  'char' => 22,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serializer',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 260,
                      'char' => 24,
                    ),
                    'name' => 'setData',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 260,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 260,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 260,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 262,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serializer',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 262,
                      'char' => 31,
                    ),
                    'name' => 'serialize',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 262,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 263,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 268,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'serialize',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 268,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 268,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 268,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 269,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Serializing a resultset will dump all related rows into a big array
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
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 237,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
            'line' => 237,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 236,
          'last-line' => 274,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'unserialize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 275,
              'char' => 41,
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
                  'variable' => 'resultset',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 277,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'keepSnapshots',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 277,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 277,
                  'char' => 48,
                ),
                3 => 
                array (
                  'variable' => 'serializer',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 277,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 279,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Di',
                    'dynamic' => 0,
                    'name' => 'getDefault',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 279,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 279,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 281,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 281,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 281,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 281,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 281,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 281,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The dependency injector container is not valid',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 284,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 284,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 284,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 285,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 287,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 287,
                  'char' => 22,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'serializer',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 287,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 287,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 287,
                'char' => 39,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'serializer',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'SerializerInterface',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 288,
                          'char' => 84,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 288,
                            'char' => 62,
                          ),
                          'name' => 'getShared',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'serializer',
                                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                                'line' => 288,
                                'char' => 83,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 288,
                              'char' => 83,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 288,
                          'char' => 84,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 288,
                        'char' => 84,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 288,
                      'char' => 84,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 289,
                  'char' => 15,
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
                      'variable' => 'resultset',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'serializer',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 289,
                          'char' => 40,
                        ),
                        'name' => 'unserialize',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 289,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 289,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 289,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 289,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 290,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'resultset',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'unserialize',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                              'line' => 291,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 291,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 291,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 291,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 292,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 294,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 294,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 294,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 294,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 294,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 294,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Invalid serialization data',
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 295,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 295,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 295,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 296,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 298,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'model',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 298,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 298,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 298,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 298,
                  'char' => 49,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'rows',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 299,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'rows',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 299,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 299,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 299,
                  'char' => 48,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'count',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'resultset',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 300,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'rows',
                            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                            'line' => 300,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                          'line' => 300,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 300,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 300,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 300,
                  'char' => 55,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'cache',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 301,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 301,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 301,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 301,
                  'char' => 49,
                ),
                4 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'columnMap',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 302,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'columnMap',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 302,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 302,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 302,
                  'char' => 53,
                ),
                5 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'hydrateMode',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 303,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'hydrateMode',
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 303,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 303,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 303,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 305,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'keepSnapshots',
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 305,
                  'char' => 58,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'resultset',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 305,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'keepSnapshots',
                    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                    'line' => 305,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 305,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                'line' => 305,
                'char' => 58,
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
                      'property' => 'keepSnapshots',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'keepSnapshots',
                        'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                        'line' => 306,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                      'line' => 306,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
                  'line' => 307,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
              'line' => 308,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Unserializing a resultset will allow to only works on the rows present in
     * the saved state
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
            'line' => 276,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
          'line' => 275,
          'last-line' => 309,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
      'line' => 27,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Resultset/Simple.zep',
    'line' => 27,
    'char' => 5,
  ),
);