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
    'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate\\Interpolator',
    'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
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
        'name' => 'Phalcon\\Translate\\Interpolator\\InterpolatorInterface',
        'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
        'line' => 13,
        'char' => 57,
      ),
    ),
    'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
    'line' => 15,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'IndexedArray',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InterpolatorInterface',
        'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
        'line' => 16,
        'char' => 1,
      ),
    ),
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
          'name' => 'replacePlaceholders',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
              'line' => 20,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                'line' => 20,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
              'line' => 20,
              'char' => 85,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'count',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                      'line' => 22,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                    'line' => 22,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                'line' => 22,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_unshift',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'placeholders',
                          'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                          'line' => 23,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                        'line' => 23,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'translation',
                          'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                          'line' => 23,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                        'line' => 23,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                    'line' => 23,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                  'line' => 25,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'call_user_func_array',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'sprintf',
                          'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                          'line' => 25,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                        'line' => 25,
                        'char' => 48,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'placeholders',
                          'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                          'line' => 25,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                        'line' => 25,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                    'line' => 25,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                  'line' => 26,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
              'line' => 28,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'translation',
                'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                'line' => 28,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
              'line' => 29,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Replaces placeholders by the values passed
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
                'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
                'line' => 21,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
            'line' => 21,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
          'line' => 20,
          'last-line' => 30,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
      'line' => 15,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Translate/Interpolator/IndexedArray.zep',
    'line' => 15,
    'char' => 5,
  ),
);