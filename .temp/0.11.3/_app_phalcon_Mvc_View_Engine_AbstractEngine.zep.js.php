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
    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\View\\Engine',
    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
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
        'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
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
        'name' => 'Phalcon\\Di\\Injectable',
        'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
        'line' => 14,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
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
        'name' => 'Phalcon\\Mvc\\ViewBaseInterface',
        'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
        'line' => 15,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
    'line' => 20,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\\Mvc\\View component.
 *',
    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
    'line' => 21,
    'char' => 8,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'AbstractEngine',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'Injectable',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'EngineInterface',
        'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
        'line' => 22,
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
          'name' => 'view',
          'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
          'line' => 27,
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
              'name' => 'view',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ViewBaseInterface',
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 28,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 28,
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
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 28,
                'char' => 81,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 28,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 28,
              'char' => 89,
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
                  'property' => 'view',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'view',
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 30,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                  'line' => 30,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 31,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 31,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                  'line' => 31,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 32,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\View\\Engine constructor
     *',
          'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
          'line' => 28,
          'last-line' => 36,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getContent',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 39,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'view',
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 39,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                  'line' => 39,
                  'char' => 27,
                ),
                'name' => 'getContent',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 39,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns cached output on another view stage
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
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 38,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
            'line' => 38,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
          'line' => 37,
          'last-line' => 44,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getView',
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
                  'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                  'line' => 47,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'view',
                  'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                  'line' => 47,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 47,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the view component related to the adapter
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
                  'value' => 'ViewBaseInterface',
                  'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                  'line' => 46,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 46,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
            'line' => 46,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
          'line' => 45,
          'last-line' => 54,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'partial',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'partialPath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 55,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 55,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 55,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 57,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'view',
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 57,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                  'line' => 57,
                  'char' => 27,
                ),
                'name' => 'partial',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'partialPath',
                      'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                      'line' => 57,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 57,
                    'char' => 47,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                      'line' => 57,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                    'line' => 57,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 57,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
              'line' => 58,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders a partial inside another view
     *
     * @param array params
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
                'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
                'line' => 56,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
            'line' => 56,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
          'line' => 55,
          'last-line' => 59,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
      'line' => 21,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/AbstractEngine.zep',
    'line' => 21,
    'char' => 14,
  ),
);