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
    'file' => '/app/phalcon/Html/Helper/Label.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/Label.zep',
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
        'file' => '/app/phalcon/Html/Helper/Label.zep',
        'line' => 13,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/Label.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\Label
 *
 * Creates a label
 *',
    'file' => '/app/phalcon/Html/Helper/Label.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Label',
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
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/Label.zep',
                'line' => 28,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/Label.zep',
              'line' => 28,
              'char' => 52,
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
                  'file' => '/app/phalcon/Html/Helper/Label.zep',
                  'line' => 30,
                  'char' => 21,
                ),
                'name' => 'renderElement',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'label',
                      'file' => '/app/phalcon/Html/Helper/Label.zep',
                      'line' => 30,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Label.zep',
                    'line' => 30,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Html/Helper/Label.zep',
                      'line' => 30,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Label.zep',
                    'line' => 30,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Html/Helper/Label.zep',
                'line' => 30,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Html/Helper/Label.zep',
              'line' => 31,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param array $attributes Any additional attributes
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
                'file' => '/app/phalcon/Html/Helper/Label.zep',
                'line' => 29,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/Label.zep',
            'line' => 29,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/Label.zep',
          'line' => 28,
          'last-line' => 32,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/Label.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Helper/Label.zep',
    'line' => 20,
    'char' => 5,
  ),
);