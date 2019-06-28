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
    'file' => '/app/phalcon/Annotations/Reader.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations',
    'file' => '/app/phalcon/Annotations/Reader.zep',
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
        'name' => 'Phalcon\\Annotations\\ReaderInterface',
        'file' => '/app/phalcon/Annotations/Reader.zep',
        'line' => 13,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Reader.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'ReflectionClass',
        'file' => '/app/phalcon/Annotations/Reader.zep',
        'line' => 14,
        'char' => 20,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Reader.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Parses docblocks returning an array with the found annotations
 *',
    'file' => '/app/phalcon/Annotations/Reader.zep',
    'line' => 19,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Reader',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ReaderInterface',
        'file' => '/app/phalcon/Annotations/Reader.zep',
        'line' => 20,
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
          'name' => 'parse',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 24,
              'char' => 43,
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
                  'variable' => 'reflection',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 26,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'comment',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 26,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'properties',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 26,
                  'char' => 44,
                ),
                3 => 
                array (
                  'variable' => 'methods',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 26,
                  'char' => 53,
                ),
                4 => 
                array (
                  'variable' => 'property',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 26,
                  'char' => 63,
                ),
                5 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 26,
                  'char' => 71,
                ),
                6 => 
                array (
                  'variable' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 27,
                  'char' => 29,
                ),
                7 => 
                array (
                  'variable' => 'line',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 27,
                  'char' => 35,
                ),
                8 => 
                array (
                  'variable' => 'annotationsProperties',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 27,
                  'char' => 58,
                ),
                9 => 
                array (
                  'variable' => 'propertyAnnotations',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 27,
                  'char' => 79,
                ),
                10 => 
                array (
                  'variable' => 'annotationsMethods',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 28,
                  'char' => 31,
                ),
                11 => 
                array (
                  'variable' => 'methodAnnotations',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 28,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 29,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'annotations',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 29,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 31,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'annotations',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 31,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 31,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 36,
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
                  'variable' => 'reflection',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'ReflectionClass',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 36,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 36,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 36,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 36,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 38,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'comment',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 38,
                      'char' => 34,
                    ),
                    'name' => 'getDocComment',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 38,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 38,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 39,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'comment',
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 39,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 39,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 39,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 39,
                'char' => 37,
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
                      'variable' => 'classAnnotations',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'phannot_parse_annotations',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'comment',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 45,
                              'char' => 24,
                            ),
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 45,
                            'char' => 24,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'reflection',
                                'file' => '/app/phalcon/Annotations/Reader.zep',
                                'line' => 46,
                                'char' => 28,
                              ),
                              'name' => 'getFileName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 46,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 46,
                            'char' => 42,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'reflection',
                                'file' => '/app/phalcon/Annotations/Reader.zep',
                                'line' => 47,
                                'char' => 28,
                              ),
                              'name' => 'getStartLine',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 48,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 48,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 48,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 48,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 53,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'classAnnotations',
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 53,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 53,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 53,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 53,
                    'char' => 49,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'annotations',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'class',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 54,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'classAnnotations',
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 54,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 54,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 55,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 56,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 61,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'properties',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 61,
                      'char' => 37,
                    ),
                    'name' => 'getProperties',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 61,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 61,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 63,
              'char' => 10,
            ),
            7 => 
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
                      'value' => 'properties',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 63,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 63,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 63,
                'char' => 30,
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
                      'variable' => 'line',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 67,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 67,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 69,
                  'char' => 15,
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
                      'variable' => 'annotationsProperties',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 69,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 69,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 71,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'properties',
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 71,
                    'char' => 40,
                  ),
                  'value' => 'property',
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
                          'variable' => 'comment',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'property',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 75,
                              'char' => 40,
                            ),
                            'name' => 'getDocComment',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 75,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 75,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 77,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'comment',
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 77,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 77,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 77,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 77,
                        'char' => 45,
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
                              'variable' => 'propertyAnnotations',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'phannot_parse_annotations',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'comment',
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 82,
                                      'char' => 32,
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 82,
                                    'char' => 32,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'reflection',
                                        'file' => '/app/phalcon/Annotations/Reader.zep',
                                        'line' => 83,
                                        'char' => 36,
                                      ),
                                      'name' => 'getFileName',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 83,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 83,
                                    'char' => 50,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'line',
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 85,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 85,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Annotations/Reader.zep',
                                'line' => 85,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 85,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 87,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'propertyAnnotations',
                                'file' => '/app/phalcon/Annotations/Reader.zep',
                                'line' => 87,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 87,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 87,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 87,
                            'char' => 60,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'annotationsProperties',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'property-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'property',
                                        'file' => '/app/phalcon/Annotations/Reader.zep',
                                        'line' => 88,
                                        'char' => 60,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'name',
                                        'file' => '/app/phalcon/Annotations/Reader.zep',
                                        'line' => 88,
                                        'char' => 65,
                                      ),
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 88,
                                      'char' => 65,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'propertyAnnotations',
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 88,
                                    'char' => 88,
                                  ),
                                  'file' => '/app/phalcon/Annotations/Reader.zep',
                                  'line' => 88,
                                  'char' => 88,
                                ),
                              ),
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 89,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 90,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 91,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 93,
                  'char' => 14,
                ),
                3 => 
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
                          'value' => 'annotationsProperties',
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 93,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 93,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 93,
                    'char' => 45,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'annotations',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'properties',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 94,
                              'char' => 43,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'annotationsProperties',
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 94,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 94,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 95,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 101,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'methods',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 101,
                      'char' => 34,
                    ),
                    'name' => 'getMethods',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 101,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 101,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 103,
              'char' => 10,
            ),
            9 => 
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
                      'value' => 'methods',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 103,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 103,
                    'char' => 25,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 103,
                'char' => 27,
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
                      'variable' => 'annotationsMethods',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 104,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 104,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 106,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'methods',
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 106,
                    'char' => 35,
                  ),
                  'value' => 'method',
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
                          'variable' => 'comment',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'method',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 110,
                              'char' => 38,
                            ),
                            'name' => 'getDocComment',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 110,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 110,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 112,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'comment',
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 112,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 112,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 112,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 112,
                        'char' => 45,
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
                              'variable' => 'methodAnnotations',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'phannot_parse_annotations',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'comment',
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 117,
                                      'char' => 32,
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 117,
                                    'char' => 32,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'method',
                                        'file' => '/app/phalcon/Annotations/Reader.zep',
                                        'line' => 118,
                                        'char' => 32,
                                      ),
                                      'name' => 'getFileName',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 118,
                                      'char' => 46,
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 118,
                                    'char' => 46,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'method',
                                        'file' => '/app/phalcon/Annotations/Reader.zep',
                                        'line' => 119,
                                        'char' => 32,
                                      ),
                                      'name' => 'getStartLine',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 120,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 120,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Annotations/Reader.zep',
                                'line' => 120,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 120,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 122,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'methodAnnotations',
                                'file' => '/app/phalcon/Annotations/Reader.zep',
                                'line' => 122,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 122,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 122,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 122,
                            'char' => 58,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'annotationsMethods',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'property-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'method',
                                        'file' => '/app/phalcon/Annotations/Reader.zep',
                                        'line' => 123,
                                        'char' => 55,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'name',
                                        'file' => '/app/phalcon/Annotations/Reader.zep',
                                        'line' => 123,
                                        'char' => 60,
                                      ),
                                      'file' => '/app/phalcon/Annotations/Reader.zep',
                                      'line' => 123,
                                      'char' => 60,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'methodAnnotations',
                                    'file' => '/app/phalcon/Annotations/Reader.zep',
                                    'line' => 123,
                                    'char' => 81,
                                  ),
                                  'file' => '/app/phalcon/Annotations/Reader.zep',
                                  'line' => 123,
                                  'char' => 81,
                                ),
                              ),
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 124,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 125,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 126,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 128,
                  'char' => 14,
                ),
                2 => 
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
                          'value' => 'annotationsMethods',
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 128,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 128,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 128,
                    'char' => 42,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'annotations',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'methods',
                              'file' => '/app/phalcon/Annotations/Reader.zep',
                              'line' => 129,
                              'char' => 40,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'annotationsMethods',
                            'file' => '/app/phalcon/Annotations/Reader.zep',
                            'line' => 129,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Annotations/Reader.zep',
                          'line' => 129,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 130,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 131,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 133,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'annotations',
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 133,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 134,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads annotations from the class docblocks, its methods and/or properties
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 25,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Reader.zep',
            'line' => 25,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reader.zep',
          'line' => 24,
          'last-line' => 138,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'parseDocBlock',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'docBlock',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 139,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 139,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 139,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'line',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 139,
                'char' => 83,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 139,
              'char' => 83,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'file',
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 141,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 141,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 141,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 141,
                'char' => 34,
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
                      'variable' => 'file',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'eval code',
                        'file' => '/app/phalcon/Annotations/Reader.zep',
                        'line' => 142,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 142,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reader.zep',
                  'line' => 143,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 145,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'phannot_parse_annotations',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'docBlock',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 145,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 145,
                    'char' => 50,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'file',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 145,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 145,
                    'char' => 56,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'line',
                      'file' => '/app/phalcon/Annotations/Reader.zep',
                      'line' => 145,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Annotations/Reader.zep',
                    'line' => 145,
                    'char' => 62,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 145,
                'char' => 63,
              ),
              'file' => '/app/phalcon/Annotations/Reader.zep',
              'line' => 146,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Parses a raw doc block returning the annotations found
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Reader.zep',
                'line' => 140,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Reader.zep',
            'line' => 140,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reader.zep',
          'line' => 139,
          'last-line' => 147,
          'char' => 26,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Reader.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Annotations/Reader.zep',
    'line' => 19,
    'char' => 5,
  ),
);