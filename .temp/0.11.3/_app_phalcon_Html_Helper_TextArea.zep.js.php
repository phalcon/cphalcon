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
    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
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
        'file' => '/app/phalcon/Html/Helper/TextArea.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\TextArea
 *
 * Creates a textarea tag
 *',
    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'TextArea',
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
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/TextArea.zep',
              'line' => 26,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                'line' => 26,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/TextArea.zep',
              'line' => 26,
              'char' => 65,
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
                  'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                  'line' => 28,
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
                      'type' => 'string',
                      'value' => 'textarea',
                      'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                      'line' => 28,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                    'line' => 28,
                    'char' => 48,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                      'line' => 28,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                    'line' => 28,
                    'char' => 54,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                      'line' => 28,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                    'line' => 28,
                    'char' => 66,
                  ),
                ),
                'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                'line' => 28,
                'char' => 67,
              ),
              'file' => '/app/phalcon/Html/Helper/TextArea.zep',
              'line' => 29,
              'char' => 5,
            ),
          ),
          'docblock' => '**
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
                'file' => '/app/phalcon/Html/Helper/TextArea.zep',
                'line' => 27,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/TextArea.zep',
            'line' => 27,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/TextArea.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/TextArea.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Helper/TextArea.zep',
    'line' => 20,
    'char' => 5,
  ),
);