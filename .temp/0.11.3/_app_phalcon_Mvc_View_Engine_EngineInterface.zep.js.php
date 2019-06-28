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
    'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\View\\Engine',
    'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
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
        'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\ViewBaseInterface',
        'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Mvc\\View engine adapters
 *',
    'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'EngineInterface',
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
          'name' => 'getContent',
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
                'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
                'line' => 24,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
            'line' => 24,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
          'line' => 24,
          'last-line' => 28,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
              'line' => 29,
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
                'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
                'line' => 29,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
              'line' => 29,
              'char' => 67,
            ),
          ),
          'docblock' => '**
     * Renders a partial inside another view
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
                'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
                'line' => 29,
                'char' => 78,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
            'line' => 29,
            'char' => 78,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
          'line' => 29,
          'last-line' => 33,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'render',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
              'line' => 34,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
              'line' => 34,
              'char' => 51,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'mustClean',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
                'line' => 34,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
              'line' => 34,
              'char' => 75,
            ),
          ),
          'docblock' => '**
     * Renders a view using the template engine
     *',
          'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
          'line' => 34,
          'last-line' => 35,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
      'line' => 35,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/EngineInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);