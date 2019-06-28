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
    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
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
        'name' => 'Phalcon\\Html\\Exception',
        'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
        'line' => 13,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\ElementRaw
 *
 * Creates an element raw
 *',
    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'ElementRaw',
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
              'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
              'line' => 30,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
              'line' => 30,
              'char' => 55,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                'line' => 30,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
              'line' => 30,
              'char' => 79,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                  'line' => 32,
                  'char' => 21,
                ),
                'name' => 'renderFullElement',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'tag',
                      'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                      'line' => 32,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                    'line' => 32,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                      'line' => 32,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                    'line' => 32,
                    'char' => 49,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                      'line' => 32,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                    'line' => 32,
                    'char' => 61,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                      'line' => 32,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                    'line' => 32,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                'line' => 32,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
              'line' => 33,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param string $tag        The tag for the anchor
     * @param string $text       The text for the anchor
     * @param array  $attributes Any additional attributes
     *
     * @return string
     * @throws Exception
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
                'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
                'line' => 31,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
            'line' => 31,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
          'line' => 30,
          'last-line' => 34,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Helper/ElementRaw.zep',
    'line' => 20,
    'char' => 5,
  ),
);