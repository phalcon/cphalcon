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
    'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets\\Filters',
    'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
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
        'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
        'line' => 13,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Deletes the characters which are insignificant to JavaScript. Comments will
 * be removed. Tabs will be replaced with spaces. Carriage returns will be
 * replaced with linefeeds. Most spaces and linefeeds will be removed.
 *',
    'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Jsmin',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'FilterInterface',
        'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
        'line' => 21,
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
              'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
              'line' => 26,
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
                'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
                'line' => 28,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
              'line' => 29,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Filters the content using JSMIN
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
                'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
                'line' => 27,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
            'line' => 27,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Assets/Filters/JsMin.zep',
    'line' => 20,
    'char' => 5,
  ),
);