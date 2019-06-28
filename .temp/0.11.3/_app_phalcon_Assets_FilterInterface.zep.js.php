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
    'file' => '/app/phalcon/Assets/FilterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets',
    'file' => '/app/phalcon/Assets/FilterInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for custom Phalcon\\Assets filters
 *',
    'file' => '/app/phalcon/Assets/FilterInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'FilterInterface',
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
              'file' => '/app/phalcon/Assets/FilterInterface.zep',
              'line' => 21,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Filters the content returning a string with the filtered content
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
                'file' => '/app/phalcon/Assets/FilterInterface.zep',
                'line' => 21,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/FilterInterface.zep',
            'line' => 21,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Assets/FilterInterface.zep',
          'line' => 21,
          'last-line' => 22,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Assets/FilterInterface.zep',
      'line' => 22,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Assets/FilterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);