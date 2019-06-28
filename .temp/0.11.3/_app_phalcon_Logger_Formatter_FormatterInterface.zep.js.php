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
    'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Formatter',
    'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
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
        'name' => 'Phalcon\\Logger\\Item',
        'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\FormatterInterface
 *
 * This interface must be implemented by formatters in Phalcon\\Logger
 *',
    'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'FormatterInterface',
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
          'name' => 'format',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
                'line' => 25,
                'char' => 38,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
              'line' => 25,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Applies a format to an item
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
                'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
                'line' => 25,
                'char' => 51,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
                'line' => 25,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
            'line' => 25,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
          'line' => 25,
          'last-line' => 26,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
      'line' => 26,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Logger/Formatter/FormatterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);