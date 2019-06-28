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
    'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets\\Filters',
    'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
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
        'name' => 'Phalcon\\Assets\\FilterInterface',
        'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
        'line' => 13,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
    'line' => 18,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Minify the css - removes comments removes newlines and line feeds keeping
 * removes last semicolon from last property
 *',
    'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
    'line' => 19,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Cssmin',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'FilterInterface',
        'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
        'line' => 20,
        'char' => 1,
      ),
    ),
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
          'name' => 'filter',
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
              'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
              'line' => 25,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'content',
                'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
                'line' => 27,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
              'line' => 28,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Filters the content using CSSMIN
     * NOTE: This functionality is not currently available
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
                'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
                'line' => 26,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
            'line' => 26,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Assets/Filters/CssMin.zep',
    'line' => 19,
    'char' => 5,
  ),
);