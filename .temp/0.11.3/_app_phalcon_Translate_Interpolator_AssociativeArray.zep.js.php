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
    'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate\\Interpolator',
    'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
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
        'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
        'line' => 13,
        'char' => 57,
      ),
    ),
    'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
    'line' => 15,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'AssociativeArray',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InterpolatorInterface',
        'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
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
              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
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
                'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                'line' => 20,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
              'line' => 20,
              'char' => 85,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                  'line' => 22,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                  'line' => 22,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
              'line' => 24,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'placeholders',
                'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                'line' => 24,
                'char' => 40,
              ),
              'key' => 'key',
              'value' => 'value',
              'reverse' => 0,
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
                      'variable' => 'translation',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'str_replace',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '%',
                                  'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                                  'line' => 26,
                                  'char' => 19,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                                  'line' => 26,
                                  'char' => 25,
                                ),
                                'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                                'line' => 26,
                                'char' => 25,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '%',
                                'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                                'line' => 26,
                                'char' => 28,
                              ),
                              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                              'line' => 26,
                              'char' => 28,
                            ),
                            'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                            'line' => 26,
                            'char' => 28,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                              'line' => 27,
                              'char' => 22,
                            ),
                            'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                            'line' => 27,
                            'char' => 22,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'translation',
                              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                              'line' => 29,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                            'line' => 29,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                        'line' => 29,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                      'line' => 29,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                  'line' => 30,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
              'line' => 32,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'translation',
                'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                'line' => 32,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
              'line' => 33,
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
                'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
                'line' => 21,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
            'line' => 21,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
          'line' => 20,
          'last-line' => 34,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
      'line' => 15,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Translate/Interpolator/AssociativeArray.zep',
    'line' => 15,
    'char' => 5,
  ),
);