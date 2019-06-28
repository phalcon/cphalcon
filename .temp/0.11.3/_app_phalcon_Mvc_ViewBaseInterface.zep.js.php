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
    'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
        'line' => 13,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\ViewInterface
 *
 * Interface for Phalcon\\Mvc\\View and Phalcon\\Mvc\\View\\Simple
 *',
    'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'ViewBaseInterface',
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
     * Returns cached output from another view stage
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
                'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
                'line' => 25,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
            'line' => 25,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParamsToView',
          'docblock' => '**
     * Returns parameters to views
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
                'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
                'line' => 30,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
            'line' => 30,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 30,
          'last-line' => 34,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getViewsDir',
          'docblock' => '**
     * Gets views directory
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
                'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
                'line' => 35,
                'char' => 45,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
                'line' => 35,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
            'line' => 35,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 35,
          'last-line' => 39,
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
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 40,
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
                'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
                'line' => 40,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 40,
              'char' => 67,
            ),
          ),
          'docblock' => '**
     * Renders a partial view
     *',
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 40,
          'last-line' => 44,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setContent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 45,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Externally sets the view content
     *',
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 45,
          'last-line' => 49,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setParamToView',
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
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 50,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 50,
              'char' => 58,
            ),
          ),
          'docblock' => '**
     * Adds parameters to views (alias of setVar)
     *',
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 50,
          'last-line' => 54,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setVar',
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
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 55,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 55,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Adds parameters to views
     *',
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 55,
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
          'name' => 'setViewsDir',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'viewsDir',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
              'line' => 61,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets views directory. Depending of your platform, always add a trailing
     * slash or backslash
     *',
          'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
          'line' => 61,
          'last-line' => 63,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
      'line' => 63,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/ViewBaseInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);