<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Helper/Number.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Helper',
    'file' => '/app/phalcon/Helper/Number.zep',
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
        'name' => 'Phalcon\\Helper\\Exception',
        'file' => '/app/phalcon/Helper/Number.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Helper/Number.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Helper\\number
 *
 * This class offers numeric functions for the framework
 *',
    'file' => '/app/phalcon/Helper/Number.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Number',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'between',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Number.zep',
              'line' => 25,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'from',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Number.zep',
              'line' => 25,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'to',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Number.zep',
              'line' => 25,
              'char' => 69,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'greater-equal',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Helper/Number.zep',
                    'line' => 27,
                    'char' => 22,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'from',
                    'file' => '/app/phalcon/Helper/Number.zep',
                    'line' => 27,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Helper/Number.zep',
                  'line' => 27,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'less-equal',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Helper/Number.zep',
                    'line' => 27,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'to',
                    'file' => '/app/phalcon/Helper/Number.zep',
                    'line' => 27,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Helper/Number.zep',
                  'line' => 27,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Helper/Number.zep',
                'line' => 27,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Helper/Number.zep',
              'line' => 28,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Helper method to get an array element or a default
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
                'file' => '/app/phalcon/Helper/Number.zep',
                'line' => 26,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Number.zep',
            'line' => 26,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Number.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 32,
        ),
      ),
      'file' => '/app/phalcon/Helper/Number.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Helper/Number.zep',
    'line' => 20,
    'char' => 5,
  ),
);