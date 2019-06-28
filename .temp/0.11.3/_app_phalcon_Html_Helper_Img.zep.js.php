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
    'file' => '/app/phalcon/Html/Helper/Img.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/Img.zep',
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
        'file' => '/app/phalcon/Html/Helper/Img.zep',
        'line' => 13,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/Img.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\Img
 *
 * Creates am img tag
 *',
    'file' => '/app/phalcon/Html/Helper/Img.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Img',
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
              'name' => 'src',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/Img.zep',
              'line' => 29,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/Img.zep',
                'line' => 29,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/Img.zep',
              'line' => 29,
              'char' => 65,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'overrides',
                  'file' => '/app/phalcon/Html/Helper/Img.zep',
                  'line' => 31,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/Img.zep',
              'line' => 33,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'overrides',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Html/Helper/Img.zep',
                          'line' => 33,
                          'char' => 30,
                        ),
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'src',
                          'file' => '/app/phalcon/Html/Helper/Img.zep',
                          'line' => 33,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Html/Helper/Img.zep',
                        'line' => 33,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/Img.zep',
                    'line' => 33,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Helper/Img.zep',
                  'line' => 33,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/Img.zep',
              'line' => 38,
              'char' => 13,
            ),
            2 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'attributes',
                  'file' => '/app/phalcon/Html/Helper/Img.zep',
                  'line' => 38,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'src',
                  'file' => '/app/phalcon/Html/Helper/Img.zep',
                  'line' => 38,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Html/Helper/Img.zep',
                'line' => 38,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Html/Helper/Img.zep',
              'line' => 40,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'overrides',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_merge',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'overrides',
                          'file' => '/app/phalcon/Html/Helper/Img.zep',
                          'line' => 40,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Html/Helper/Img.zep',
                        'line' => 40,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Html/Helper/Img.zep',
                          'line' => 40,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Html/Helper/Img.zep',
                        'line' => 40,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/Img.zep',
                    'line' => 40,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Html/Helper/Img.zep',
                  'line' => 40,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/Img.zep',
              'line' => 42,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Helper/Img.zep',
                  'line' => 42,
                  'char' => 21,
                ),
                'name' => 'selfClose',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'img',
                      'file' => '/app/phalcon/Html/Helper/Img.zep',
                      'line' => 42,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Img.zep',
                    'line' => 42,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'overrides',
                      'file' => '/app/phalcon/Html/Helper/Img.zep',
                      'line' => 42,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Html/Helper/Img.zep',
                    'line' => 42,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Html/Helper/Img.zep',
                'line' => 42,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Html/Helper/Img.zep',
              'line' => 43,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param string $src
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
                'file' => '/app/phalcon/Html/Helper/Img.zep',
                'line' => 30,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/Img.zep',
            'line' => 30,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/Img.zep',
          'line' => 29,
          'last-line' => 44,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/Img.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Helper/Img.zep',
    'line' => 20,
    'char' => 5,
  ),
);