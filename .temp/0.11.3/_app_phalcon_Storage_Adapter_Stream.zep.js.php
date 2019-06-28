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
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Adapter',
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
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
        'name' => 'Phalcon\\Helper\\Str',
        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Storage\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
        'line' => 15,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Storage\\Exception',
        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
        'line' => 16,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Storage\\SerializerFactory',
        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
        'line' => 18,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 22,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Stream adapter
 *',
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 23,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Stream',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'cacheDir',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 28,
            'char' => 26,
          ),
          'docblock' => '**
    * @var string
    *',
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 32,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 33,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 41,
          'char' => 6,
        ),
      ),
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
              'name' => 'factory',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'SerializerFactory',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 42,
                'char' => 59,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 42,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 42,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 42,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 42,
              'char' => 88,
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
                  'variable' => 'cacheDir',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 44,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 46,
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
                  'variable' => 'cacheDir',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 46,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 46,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'cacheDir',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 46,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 46,
                        'char' => 50,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 46,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 46,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 46,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 46,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 47,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'cacheDir',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 47,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 47,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The \'cacheDir\' must be specified in the options',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 48,
                          'char' => 80,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 48,
                        'char' => 80,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 48,
                    'char' => 81,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 49,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 54,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'cacheDir',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Str',
                    'dynamic' => 0,
                    'name' => 'dirSeparator',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cacheDir',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 54,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 54,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 54,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 54,
                  'char' => 57,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'phstrm-',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 55,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 55,
                  'char' => 37,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 56,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 56,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 58,
              'char' => 14,
            ),
            4 => 
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
                      'type' => 'variable',
                      'value' => 'factory',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 58,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 58,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 58,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 58,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 58,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 60,
              'char' => 12,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 60,
                  'char' => 14,
                ),
                'name' => 'initSerializer',
                'call-type' => 1,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 60,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stream constructor.
     *
     * @param array $options
     *
     * @throws Exception
     *',
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 42,
          'last-line' => 65,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
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
                  'variable' => 'directory',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 68,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'iterator',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 68,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'file',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 68,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 68,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 70,
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
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 70,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 70,
                  'char' => 29,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'directory',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Str',
                    'dynamic' => 0,
                    'name' => 'dirSeparator',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 71,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'cacheDir',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 71,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 71,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 71,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 71,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 71,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'iterator',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 72,
                      'char' => 30,
                    ),
                    'name' => 'rglob',
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
                            'type' => 'variable',
                            'value' => 'directory',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 72,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '/*',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 72,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 72,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 72,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 72,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 72,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 74,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'iterator',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 74,
                'char' => 30,
              ),
              'value' => 'file',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'is_dir',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 75,
                              'char' => 28,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 75,
                            'char' => 28,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 75,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 75,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'unlink',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 75,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 75,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 75,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 75,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 75,
                    'char' => 47,
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
                          'variable' => 'result',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 76,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 76,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 77,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 78,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 80,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 80,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Flushes/clears the cache
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 66,
          'last-line' => 91,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'decrement',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 92,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 92,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 92,
              'char' => 57,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 94,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 96,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 96,
                    'char' => 18,
                  ),
                  'name' => 'has',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 96,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 96,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 96,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 96,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 97,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 100,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 100,
                      'char' => 25,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 100,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 100,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 100,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 100,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'sub',
                    'left' => 
                    array (
                      'type' => 'cast',
                      'left' => 'int',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 101,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 101,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 101,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 101,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 101,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 103,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 103,
                  'char' => 21,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 103,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 103,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 103,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 103,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 103,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     * @throws \\Exception
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 92,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 93,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 93,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 92,
          'last-line' => 112,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'delete',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 113,
              'char' => 39,
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
                  'variable' => 'filepath',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 115,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 117,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 117,
                    'char' => 18,
                  ),
                  'name' => 'has',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 117,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 117,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 117,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 117,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 118,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 119,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 121,
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
                  'variable' => 'filepath',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 121,
                      'char' => 29,
                    ),
                    'name' => 'getFilepath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 121,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 121,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 121,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 121,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 123,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'unlink',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filepath',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 123,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 123,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 123,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 124,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
     *
     * @param string $key
     *
     * @return bool
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 113,
          'last-line' => 133,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 134,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 134,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 134,
              'char' => 61,
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
                  'variable' => 'content',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 136,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'payload',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 136,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'filepath',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 136,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 138,
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
                  'variable' => 'filepath',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 138,
                      'char' => 29,
                    ),
                    'name' => 'getFilepath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 138,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 138,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 138,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 138,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 140,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'file_exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filepath',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 140,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 140,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 140,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 140,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 141,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 142,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 144,
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
                  'variable' => 'payload',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'file_get_contents',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filepath',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 144,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 144,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 144,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 144,
                  'char' => 52,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'payload',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'json_decode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'payload',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 145,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 145,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 145,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 145,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 145,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 145,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 147,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'json_last_error',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 147,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'constant',
                  'value' => 'JSON_ERROR_NONE',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 147,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 147,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 148,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 149,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 151,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 151,
                  'char' => 17,
                ),
                'name' => 'isExpired',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'payload',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 151,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 151,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 151,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 152,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 153,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 155,
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
                  'variable' => 'content',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'payload',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 155,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 155,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'content',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 155,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 155,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 155,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 155,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 155,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 155,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 157,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 157,
                  'char' => 21,
                ),
                'name' => 'getUnserializedData',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'content',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 157,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 157,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 157,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 157,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 157,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 158,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
     *
     * @param string $key
     * @param null   $defaultValue
     *
     * @return mixed|null
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 134,
          'last-line' => 163,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAdapter',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 166,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapter',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 166,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 166,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 167,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 164,
          'last-line' => 171,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getKeys',
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
                  'variable' => 'directory',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 174,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'iterator',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 174,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'file',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 174,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'split',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 174,
                  'char' => 45,
                ),
                4 => 
                array (
                  'variable' => 'results',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 174,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 176,
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
                  'variable' => 'results',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 176,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 176,
                  'char' => 27,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'directory',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Str',
                    'dynamic' => 0,
                    'name' => 'dirSeparator',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 177,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'cacheDir',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 177,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 177,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 177,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 177,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 177,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'iterator',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 178,
                      'char' => 30,
                    ),
                    'name' => 'rglob',
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
                            'type' => 'variable',
                            'value' => 'directory',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 178,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '/*',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 178,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 178,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 178,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 178,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 178,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 180,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'iterator',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 180,
                'char' => 30,
              ),
              'value' => 'file',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'is_dir',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'file',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 181,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 181,
                          'char' => 28,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 181,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 181,
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
                          'variable' => 'split',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'explode',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/',
                                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                  'line' => 182,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 182,
                                'char' => 42,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'file',
                                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                  'line' => 182,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 182,
                                'char' => 48,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 182,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 182,
                          'char' => 49,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'results',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 183,
                                'char' => 38,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'prefix',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 183,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 183,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'last',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'split',
                                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                    'line' => 183,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                  'line' => 183,
                                  'char' => 63,
                                ),
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 183,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 183,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 183,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 184,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 185,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 187,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'results',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 187,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 188,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stores data in the adapter
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
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 173,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 173,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 172,
          'last-line' => 196,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 197,
              'char' => 36,
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
                  'variable' => 'payload',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 199,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'filepath',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 199,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 201,
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
                  'variable' => 'filepath',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 201,
                      'char' => 29,
                    ),
                    'name' => 'getFilepath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 201,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 201,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 201,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 201,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 203,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'file_exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filepath',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 203,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 203,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 203,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 203,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 204,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 205,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 207,
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
                  'variable' => 'payload',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'file_get_contents',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filepath',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 207,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 207,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 207,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 207,
                  'char' => 50,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'payload',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'json_decode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'payload',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 208,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 208,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 208,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 208,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 210,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 210,
                    'char' => 22,
                  ),
                  'name' => 'isExpired',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'payload',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 210,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 210,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 210,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 210,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 211,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if an element exists in the cache and is not expired
     *
     * @param string $key
     *
     * @return bool
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 198,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 198,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 197,
          'last-line' => 221,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'increment',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 222,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 222,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 222,
              'char' => 57,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 224,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 226,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 226,
                    'char' => 18,
                  ),
                  'name' => 'has',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 226,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 226,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 226,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 226,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 227,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 228,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 230,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 230,
                      'char' => 25,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 230,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 230,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 230,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 230,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'cast',
                      'left' => 'int',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 231,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 231,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 231,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 231,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 231,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 233,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 233,
                  'char' => 21,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 233,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 233,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 233,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 233,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 233,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 234,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     * @throws \\Exception
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 222,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 223,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 223,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 222,
          'last-line' => 245,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 246,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 246,
              'char' => 47,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ttl',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 246,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 246,
              'char' => 63,
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
                  'variable' => 'directory',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 248,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 249,
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
                  'variable' => 'payload',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 249,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 251,
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
                  'variable' => 'payload',
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
                          'value' => 'created',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 252,
                          'char' => 25,
                        ),
                        'value' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'time',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 252,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 252,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'ttl',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 253,
                          'char' => 25,
                        ),
                        'value' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 253,
                            'char' => 32,
                          ),
                          'name' => 'getTtl',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'ttl',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 253,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 253,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 253,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 253,
                        'char' => 44,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'content',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 254,
                          'char' => 25,
                        ),
                        'value' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 254,
                            'char' => 32,
                          ),
                          'name' => 'getSerializedData',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 254,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 254,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 255,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 255,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 255,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 255,
                  'char' => 14,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'payload',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'json_encode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'payload',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 256,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 256,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 256,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 256,
                  'char' => 45,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'directory',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 257,
                      'char' => 30,
                    ),
                    'name' => 'getDir',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 257,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 257,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 257,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 257,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 259,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_dir',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'directory',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 259,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 259,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 259,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 259,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mkdir',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'directory',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 260,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 260,
                        'char' => 28,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0777',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 260,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 260,
                        'char' => 34,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 260,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 260,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 260,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 261,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 263,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 263,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'file_put_contents',
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
                          'type' => 'variable',
                          'value' => 'directory',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 263,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 263,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 263,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 263,
                      'char' => 59,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'payload',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 263,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 263,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 263,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 263,
                'char' => 69,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 264,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stores data in the adapter
     *
     * @param string $key
     * @param mixed  $value
     * @param null   $ttl
     *
     * @return bool
     * @throws \\Exception
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 247,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 247,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 246,
          'last-line' => 272,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getDir',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 273,
                'char' => 43,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 273,
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
                  'variable' => 'dirPrefix',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 275,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'dirFromFile',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 275,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 277,
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
                  'variable' => 'dirPrefix',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 277,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'cacheDir',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 277,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 277,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 277,
                        'char' => 49,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'prefix',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 277,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 277,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 277,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 277,
                  'char' => 56,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'dirFromFile',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Str',
                    'dynamic' => 0,
                    'name' => 'dirFromFile',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
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
                                'type' => 'property-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                  'line' => 279,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'prefix',
                                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                  'line' => 279,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 279,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 279,
                              'char' => 41,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 279,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 279,
                              'char' => 43,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'key',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 279,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 279,
                              'char' => 48,
                            ),
                            3 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 279,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 279,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 280,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 280,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 280,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 280,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 282,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'scall',
                  'dynamic-class' => 0,
                  'class' => 'Str',
                  'dynamic' => 0,
                  'name' => 'dirSeparator',
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dirPrefix',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 282,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 282,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 282,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'dirFromFile',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 282,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 282,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 283,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the folder based on the cacheDir and the prefix
     *
     * @param string $key
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
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 274,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 274,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 273,
          'last-line' => 287,
          'char' => 20,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getFilepath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 288,
              'char' => 45,
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 290,
                    'char' => 21,
                  ),
                  'name' => 'getDir',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 290,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 290,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 290,
                  'char' => 34,
                ),
                'right' => 
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
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 290,
                          'char' => 53,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 290,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 290,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 290,
                      'char' => 60,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 290,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 290,
                      'char' => 62,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 290,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 290,
                      'char' => 67,
                    ),
                    3 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 290,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 290,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 290,
                  'char' => 71,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 290,
                'char' => 71,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 291,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the full path to the file
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
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 289,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 289,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 288,
          'last-line' => 299,
          'char' => 20,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'isExpired',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'payload',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 300,
              'char' => 46,
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
                  'variable' => 'created',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 302,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'ttl',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 302,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 304,
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
                  'variable' => 'created',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'payload',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 304,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 304,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'created',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 304,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 304,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'time',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 304,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 304,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 304,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 304,
                  'char' => 57,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'ttl',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'payload',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 305,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 305,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'ttl',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 305,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 305,
                        'char' => 44,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '3600',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 305,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 305,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 305,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 305,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 307,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'less',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'created',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 307,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ttl',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 307,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 307,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 307,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'time',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 307,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 307,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 308,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns if the cache has expired for this item or not
     *
     * @param array $payload
     *
     * @return bool
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 301,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 301,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 300,
          'last-line' => 314,
          'char' => 20,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'rglob',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'pattern',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 315,
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
                  'variable' => 'dir',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 317,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'dirName',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 317,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'files',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 317,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'flags',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 317,
                  'char' => 39,
                ),
                4 => 
                array (
                  'variable' => 'recurse',
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 317,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 319,
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
                  'variable' => 'dirName',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'dirname',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'pattern',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 319,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 319,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 319,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '/*',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 319,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 319,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 319,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'files',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'glob',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pattern',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 320,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 320,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 320,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 320,
                  'char' => 36,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'flags',
                  'expr' => 
                  array (
                    'type' => 'bitwise_or',
                    'left' => 
                    array (
                      'type' => 'constant',
                      'value' => 'GLOB_ONLYDIR',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 321,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'GLOB_NOSORT',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 321,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 321,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 321,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 323,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'glob',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dirName',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 323,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 323,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'flags',
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 323,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                    'line' => 323,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 323,
                'char' => 41,
              ),
              'value' => 'dir',
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
                      'variable' => 'dir',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'dir',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 324,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '/',
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 324,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 324,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'basename',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'pattern',
                                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                                'line' => 324,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 324,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 324,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 324,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 324,
                      'char' => 54,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'recurse',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                          'line' => 325,
                          'char' => 32,
                        ),
                        'name' => 'rglob',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'dir',
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 325,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 325,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 325,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 325,
                      'char' => 43,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'files',
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
                              'value' => 'files',
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 326,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 326,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'recurse',
                              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                              'line' => 326,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                            'line' => 326,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                        'line' => 326,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                      'line' => 326,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                  'line' => 327,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 329,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'files',
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 329,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
              'line' => 330,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param string $pattern
     *
     * @return array
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
                'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
                'line' => 316,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
            'line' => 316,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
          'line' => 315,
          'last-line' => 331,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/Adapter/Stream.zep',
    'line' => 23,
    'char' => 5,
  ),
);