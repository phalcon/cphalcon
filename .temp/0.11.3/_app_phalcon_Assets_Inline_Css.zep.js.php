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
    'file' => '/app/phalcon/Assets/Inline/Css.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets\\Inline',
    'file' => '/app/phalcon/Assets/Inline/Css.zep',
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
        'name' => 'Phalcon\\Assets\\Inline',
        'alias' => 'InlineBase',
        'file' => '/app/phalcon/Assets/Inline/Css.zep',
        'line' => 13,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Assets/Inline/Css.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents an inlined CSS
 *',
    'file' => '/app/phalcon/Assets/Inline/Css.zep',
    'line' => 18,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Css',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'InlineBase',
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
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Inline/Css.zep',
              'line' => 23,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Inline/Css.zep',
                'line' => 23,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Inline/Css.zep',
              'line' => 23,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Inline/Css.zep',
                'line' => 23,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Inline/Css.zep',
              'line' => 23,
              'char' => 86,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'attributes',
                  'file' => '/app/phalcon/Assets/Inline/Css.zep',
                  'line' => 25,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Assets/Inline/Css.zep',
                  'line' => 25,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Assets/Inline/Css.zep',
                'line' => 25,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'attributes',
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
                              'value' => 'type',
                              'file' => '/app/phalcon/Assets/Inline/Css.zep',
                              'line' => 27,
                              'char' => 21,
                            ),
                            'value' => 
                            array (
                              'type' => 'string',
                              'value' => 'text/css',
                              'file' => '/app/phalcon/Assets/Inline/Css.zep',
                              'line' => 28,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Assets/Inline/Css.zep',
                            'line' => 28,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Inline/Css.zep',
                        'line' => 28,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Assets/Inline/Css.zep',
                      'line' => 28,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Inline/Css.zep',
                  'line' => 29,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Inline/Css.zep',
              'line' => 31,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'css',
                      'file' => '/app/phalcon/Assets/Inline/Css.zep',
                      'line' => 31,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Assets/Inline/Css.zep',
                    'line' => 31,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'content',
                      'file' => '/app/phalcon/Assets/Inline/Css.zep',
                      'line' => 31,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Assets/Inline/Css.zep',
                    'line' => 31,
                    'char' => 41,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filter',
                      'file' => '/app/phalcon/Assets/Inline/Css.zep',
                      'line' => 31,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Assets/Inline/Css.zep',
                    'line' => 31,
                    'char' => 49,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Assets/Inline/Css.zep',
                      'line' => 31,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Assets/Inline/Css.zep',
                    'line' => 31,
                    'char' => 61,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Inline/Css.zep',
                'line' => 31,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Assets/Inline/Css.zep',
              'line' => 32,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Assets\\Inline\\Css constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Inline/Css.zep',
            'line' => 24,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Inline/Css.zep',
          'line' => 23,
          'last-line' => 33,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Assets/Inline/Css.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Assets/Inline/Css.zep',
    'line' => 18,
    'char' => 5,
  ),
);