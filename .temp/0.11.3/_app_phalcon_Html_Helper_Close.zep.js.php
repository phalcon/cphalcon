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
    'file' => '/app/phalcon/Html/Helper/Close.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/Close.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\Close
 *
 * Creates a closing tag
 *',
    'file' => '/app/phalcon/Html/Helper/Close.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Close',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractHelper',
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
          'name' => '__invoke',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/Close.zep',
              'line' => 25,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '</',
                    'file' => '/app/phalcon/Html/Helper/Close.zep',
                    'line' => 27,
                    'char' => 19,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tag',
                    'file' => '/app/phalcon/Html/Helper/Close.zep',
                    'line' => 27,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Html/Helper/Close.zep',
                  'line' => 27,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '>',
                  'file' => '/app/phalcon/Html/Helper/Close.zep',
                  'line' => 27,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Html/Helper/Close.zep',
                'line' => 27,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Html/Helper/Close.zep',
              'line' => 28,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param string $tag The tag
     *
     * @return string
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
                'file' => '/app/phalcon/Html/Helper/Close.zep',
                'line' => 26,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/Close.zep',
            'line' => 26,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/Close.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/Close.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Helper/Close.zep',
    'line' => 18,
    'char' => 5,
  ),
);