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
    'file' => '/app/phalcon/Html/Helper/Element.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/Element.zep',
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
        'name' => 'Phalcon\\Html\\Helper\\AbstractHelper',
        'file' => '/app/phalcon/Html/Helper/Element.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/Element.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\Address
 *
 * Creates an element
 *',
    'file' => '/app/phalcon/Html/Helper/Element.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Element',
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
              'file' => '/app/phalcon/Html/Helper/Element.zep',
              'line' => 27,
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
              'file' => '/app/phalcon/Html/Helper/Element.zep',
              'line' => 27,
              'char' => 55,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/Element.zep',
                'line' => 27,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/Element.zep',
              'line' => 27,
              'char' => 78,
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
                  'file' => '/app/phalcon/Html/Helper/Element.zep',
                  'line' => 29,
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
                      'file' => '/app/phalcon/Html/Helper/Element.zep',
                      'line' => 29,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Element.zep',
                    'line' => 29,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Html/Helper/Element.zep',
                      'line' => 29,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Element.zep',
                    'line' => 29,
                    'char' => 49,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Html/Helper/Element.zep',
                      'line' => 29,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Element.zep',
                    'line' => 29,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Html/Helper/Element.zep',
                'line' => 29,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Html/Helper/Element.zep',
              'line' => 30,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var string tag        The tag name
     * @var string text       The text for the anchor
     * @var array  attributes Any additional attributes
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
                'file' => '/app/phalcon/Html/Helper/Element.zep',
                'line' => 28,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/Element.zep',
            'line' => 28,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/Element.zep',
          'line' => 27,
          'last-line' => 31,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/Element.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Helper/Element.zep',
    'line' => 20,
    'char' => 5,
  ),
);