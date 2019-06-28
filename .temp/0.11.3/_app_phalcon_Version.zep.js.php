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
    'file' => '/app/phalcon/Version.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Version.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class allows to get the installed version of the framework
 *',
    'file' => '/app/phalcon/Version.zep',
    'line' => 16,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Version',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => '_getVersion',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'int',
                      'value' => '4',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 85,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 85,
                    'char' => 18,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 85,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 85,
                    'char' => 21,
                  ),
                  2 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 85,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 85,
                    'char' => 24,
                  ),
                  3 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'int',
                      'value' => '2',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 85,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 85,
                    'char' => 27,
                  ),
                  4 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 85,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 85,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Version.zep',
                'line' => 85,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 86,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Area where the version number is set. The format is as follows:
     * ABBCCDE
     *
     * A - Major version
     * B - Med version (two digits)
     * C - Min version (two digits)
     * D - Special release: 1 = alpha, 2 = beta, 3 = RC, 4 = stable
     * E - Special release version i.e. RC1, Beta2 etc.
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
                'file' => '/app/phalcon/Version.zep',
                'line' => 84,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Version.zep',
            'line' => 84,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Version.zep',
          'line' => 83,
          'last-line' => 90,
          'char' => 29,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'final',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => '_getSpecial',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'special',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Version.zep',
              'line' => 91,
              'char' => 60,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'suffix',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 93,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 93,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 95,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'special',
                'file' => '/app/phalcon/Version.zep',
                'line' => 95,
                'char' => 24,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 96,
                    'char' => 19,
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
                          'variable' => 'suffix',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'alpha',
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 97,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 97,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 98,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 99,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 99,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '2',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 99,
                    'char' => 19,
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
                          'variable' => 'suffix',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'beta',
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 100,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 100,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 101,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 102,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 102,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '3',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 102,
                    'char' => 19,
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
                          'variable' => 'suffix',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'RC',
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 103,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 103,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 104,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 105,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 105,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 107,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'suffix',
                'file' => '/app/phalcon/Version.zep',
                'line' => 107,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Translates a number to a special release.
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
                'file' => '/app/phalcon/Version.zep',
                'line' => 92,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Version.zep',
            'line' => 92,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Version.zep',
          'line' => 91,
          'last-line' => 116,
          'char' => 35,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'get',
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
                  'variable' => 'version',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 119,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'major',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 119,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'medium',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 119,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'minor',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 119,
                  'char' => 42,
                ),
                4 => 
                array (
                  'variable' => 'special',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 119,
                  'char' => 51,
                ),
                5 => 
                array (
                  'variable' => 'specialNumber',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 119,
                  'char' => 66,
                ),
                6 => 
                array (
                  'variable' => 'suffix',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 119,
                  'char' => 74,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 120,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 120,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 122,
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
                  'variable' => 'version',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'static',
                    'dynamic' => 0,
                    'name' => '_getVersion',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 122,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 122,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 124,
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
                  'variable' => 'major',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 124,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 124,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_MAJOR',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 124,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 124,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 124,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 124,
                  'char' => 57,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'medium',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 125,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 125,
                        'char' => 57,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_MEDIUM',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 125,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 125,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 125,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 125,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'minor',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 126,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 126,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_MINOR',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 126,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 126,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 126,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 126,
                  'char' => 57,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'special',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 127,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 127,
                        'char' => 58,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_SPECIAL',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 127,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 127,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 127,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 127,
                  'char' => 59,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'specialNumber',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 128,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 128,
                        'char' => 65,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_SPECIAL_NUMBER',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 128,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 128,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 128,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 128,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 130,
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
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'major',
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 130,
                            'char' => 29,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '.',
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 130,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 130,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'medium',
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 130,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 130,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '.',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 130,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 130,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'minor',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 130,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 130,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 130,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 131,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'suffix',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'static',
                    'dynamic' => 0,
                    'name' => '_getSpecial',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'special',
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 131,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 131,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 131,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 131,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 133,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'suffix',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 133,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 133,
                  'char' => 23,
                ),
                'file' => '/app/phalcon/Version.zep',
                'line' => 133,
                'char' => 23,
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
                      'operator' => 'concat-assign',
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '-',
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 139,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'suffix',
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 139,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 139,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 139,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 141,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'specialNumber',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 141,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 141,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 141,
                    'char' => 35,
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
                          'operator' => 'concat-assign',
                          'variable' => 'result',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => '.',
                              'file' => '/app/phalcon/Version.zep',
                              'line' => 142,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'specialNumber',
                              'file' => '/app/phalcon/Version.zep',
                              'line' => 142,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 142,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 142,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 143,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 144,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 146,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Version.zep',
                'line' => 146,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 147,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the active version (string)
     *
     * ```php
     * echo Phalcon\\Version::get();
     * ```
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
                'file' => '/app/phalcon/Version.zep',
                'line' => 118,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Version.zep',
            'line' => 118,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Version.zep',
          'line' => 117,
          'last-line' => 155,
          'char' => 26,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getId',
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
                  'variable' => 'version',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 158,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'major',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 158,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'medium',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 158,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'minor',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 158,
                  'char' => 42,
                ),
                4 => 
                array (
                  'variable' => 'special',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 158,
                  'char' => 51,
                ),
                5 => 
                array (
                  'variable' => 'specialNumber',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 158,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 160,
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
                  'variable' => 'version',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'static',
                    'dynamic' => 0,
                    'name' => '_getVersion',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 160,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 160,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 162,
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
                  'variable' => 'major',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 162,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 162,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_MAJOR',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 162,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 162,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 162,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 162,
                  'char' => 57,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'medium',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 163,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 163,
                        'char' => 57,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_MEDIUM',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 163,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 163,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 163,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 163,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'minor',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 164,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 164,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_MINOR',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 164,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 164,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 164,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 164,
                  'char' => 57,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'special',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 165,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 165,
                        'char' => 58,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_SPECIAL',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 165,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 165,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 165,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 165,
                  'char' => 59,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'specialNumber',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 166,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 166,
                        'char' => 65,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'VERSION_SPECIAL_NUMBER',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 166,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 166,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 166,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 166,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 168,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'major',
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 168,
                        'char' => 22,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'sprintf',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '%02s',
                              'file' => '/app/phalcon/Version.zep',
                              'line' => 168,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 168,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'medium',
                              'file' => '/app/phalcon/Version.zep',
                              'line' => 168,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 168,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 168,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 168,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'sprintf',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '%02s',
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 168,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 168,
                          'char' => 60,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minor',
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 168,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 168,
                          'char' => 67,
                        ),
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 168,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 168,
                    'char' => 69,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'special',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 168,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 168,
                  'char' => 79,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'specialNumber',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 168,
                  'char' => 94,
                ),
                'file' => '/app/phalcon/Version.zep',
                'line' => 168,
                'char' => 94,
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 169,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the numeric active version
     *
     * ```php
     * echo Phalcon\\Version::getId();
     * ```
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
                'file' => '/app/phalcon/Version.zep',
                'line' => 157,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Version.zep',
            'line' => 157,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Version.zep',
          'line' => 156,
          'last-line' => 180,
          'char' => 26,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'getPart',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'part',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Version.zep',
              'line' => 181,
              'char' => 44,
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
                  'variable' => 'version',
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 183,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 185,
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
                  'variable' => 'version',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'static',
                    'dynamic' => 0,
                    'name' => '_getVersion',
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 185,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 185,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 187,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'part',
                'file' => '/app/phalcon/Version.zep',
                'line' => 187,
                'char' => 21,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 188,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'VERSION_MAJOR',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 188,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 188,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 189,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 189,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'VERSION_MEDIUM',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 189,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 189,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 190,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 190,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'VERSION_MINOR',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 190,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 190,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 191,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 191,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'VERSION_SPECIAL_NUMBER',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 191,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 191,
                    'char' => 46,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'version',
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 192,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'part',
                          'file' => '/app/phalcon/Version.zep',
                          'line' => 192,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 192,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 194,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 194,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 194,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'VERSION_SPECIAL',
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 194,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Version.zep',
                    'line' => 194,
                    'char' => 39,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'static',
                        'dynamic' => 0,
                        'name' => '_getSpecial',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'version',
                                'file' => '/app/phalcon/Version.zep',
                                'line' => 196,
                                'char' => 28,
                              ),
                              'right' => 
                              array (
                                'type' => 'static-constant-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'self',
                                  'file' => '/app/phalcon/Version.zep',
                                  'line' => 196,
                                  'char' => 50,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'VERSION_SPECIAL',
                                  'file' => '/app/phalcon/Version.zep',
                                  'line' => 196,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Version.zep',
                                'line' => 196,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Version.zep',
                              'line' => 197,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Version.zep',
                            'line' => 197,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Version.zep',
                        'line' => 197,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Version.zep',
                      'line' => 198,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Version.zep',
                  'line' => 198,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 200,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'static',
                'dynamic' => 0,
                'name' => 'get',
                'file' => '/app/phalcon/Version.zep',
                'line' => 200,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Version.zep',
              'line' => 201,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a specific part of the version. If the wrong parameter is passed
     * it will return the full version
     *
     * ```php
     * echo Phalcon\\Version::getPart(
     *     Phalcon\\Version::VERSION_MAJOR
     * );
     * ```
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
                'file' => '/app/phalcon/Version.zep',
                'line' => 182,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Version.zep',
            'line' => 182,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Version.zep',
          'line' => 181,
          'last-line' => 202,
          'char' => 26,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'VERSION_MAJOR',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Version.zep',
            'line' => 27,
            'char' => 28,
          ),
          'docblock' => '**
     * The constant referencing the major version. Returns 0
     *
     * ```php
     * echo Phalcon\\Version::getPart(
     *     Phalcon\\Version::VERSION_MAJOR
     * );
     * ```
     *',
          'file' => '/app/phalcon/Version.zep',
          'line' => 37,
          'char' => 6,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'VERSION_MEDIUM',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Version.zep',
            'line' => 38,
            'char' => 29,
          ),
          'docblock' => '**
     * The constant referencing the major version. Returns 1
     *
     * ```php
     * echo Phalcon\\Version::getPart(
     *     Phalcon\\Version::VERSION_MEDIUM
     * );
     * ```
     *',
          'file' => '/app/phalcon/Version.zep',
          'line' => 48,
          'char' => 6,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'VERSION_MINOR',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Version.zep',
            'line' => 49,
            'char' => 28,
          ),
          'docblock' => '**
     * The constant referencing the major version. Returns 2
     *
     * ```php
     * echo Phalcon\\Version::getPart(
     *     Phalcon\\Version::VERSION_MINOR
     * );
     * ```
     *',
          'file' => '/app/phalcon/Version.zep',
          'line' => 59,
          'char' => 6,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'VERSION_SPECIAL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Version.zep',
            'line' => 60,
            'char' => 30,
          ),
          'docblock' => '**
     * The constant referencing the major version. Returns 3
     *
     * ```php
     * echo Phalcon\\Version::getPart(
     *     Phalcon\\Version::VERSION_SPECIAL
     * );
     * ```
     *',
          'file' => '/app/phalcon/Version.zep',
          'line' => 70,
          'char' => 6,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'VERSION_SPECIAL_NUMBER',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Version.zep',
            'line' => 71,
            'char' => 37,
          ),
          'docblock' => '**
     * The constant referencing the major version. Returns 4
     *
     * ```php
     * echo Phalcon\\Version::getPart(
     *     Phalcon\\Version::VERSION_SPECIAL_NUMBER
     * );
     * ```
     *',
          'file' => '/app/phalcon/Version.zep',
          'line' => 82,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Version.zep',
      'line' => 16,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Version.zep',
    'line' => 16,
    'char' => 5,
  ),
);