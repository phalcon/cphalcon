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
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator\\File\\Resolution',
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
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
        'name' => 'Phalcon\\Messages\\Message',
        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
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
        'name' => 'Phalcon\\Validation\\Validation',
        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
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
        'name' => 'Phalcon\\Validation\\Validator\\File\\AbstractFile',
        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
        'line' => 15,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
    'line' => 55,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks if a file has the rigth resolution
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\File\\Resolution\\Equal;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Equal(
 *         [
 *             "resolution" => "800x600",
 *             "message"    => "The resolution of the field :field has to be equal :resolution",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Equal(
 *         [
 *             "resolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "message" => [
 *                 "file"        => "Equal resolution of file has to be 800x600",
 *                 "anotherFile" => "Equal resolution of file has to be 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
    'line' => 56,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Equal',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractFile',
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
          'name' => 'template',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'The resolution of the field :field has to be equal :resolution',
            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
            'line' => 58,
            'char' => 88,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
          'line' => 62,
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
          'name' => 'validate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'validation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Validation',
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                'line' => 63,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 63,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 63,
              'char' => 64,
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
                  'variable' => 'height',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 65,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'equalHeight',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 65,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'equalWidth',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 65,
                  'char' => 44,
                ),
                3 => 
                array (
                  'variable' => 'resolution',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 65,
                  'char' => 56,
                ),
                4 => 
                array (
                  'variable' => 'resolutionArray',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 65,
                  'char' => 73,
                ),
                5 => 
                array (
                  'variable' => 'tmp',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 66,
                  'char' => 16,
                ),
                6 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 66,
                  'char' => 23,
                ),
                7 => 
                array (
                  'variable' => 'width',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 66,
                  'char' => 30,
                ),
                8 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 66,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 69,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 69,
                    'char' => 17,
                  ),
                  'name' => 'checkUpload',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'validation',
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 69,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 69,
                      'char' => 40,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 69,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 69,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 69,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 69,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                'line' => 69,
                'char' => 59,
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
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 70,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 71,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 73,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 73,
                      'char' => 33,
                    ),
                    'name' => 'getValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 73,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 73,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 73,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 73,
                  'char' => 49,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'tmp',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'getimagesize',
                    'call-type' => 1,
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
                            'value' => 'value',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                            'line' => 74,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'tmp_name',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                            'line' => 74,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 74,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 74,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 74,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 74,
                  'char' => 51,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'width',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'tmp',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 75,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 75,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 75,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 75,
                  'char' => 28,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'height',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'tmp',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 76,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 76,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 76,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 76,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 78,
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
                  'variable' => 'resolution',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 78,
                      'char' => 31,
                    ),
                    'name' => 'getOption',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'resolution',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 78,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 78,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 78,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 78,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 80,
              'char' => 10,
            ),
            4 => 
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
                    'value' => 'resolution',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 80,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 80,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 80,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                'line' => 80,
                'char' => 39,
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
                      'variable' => 'resolution',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'resolution',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 81,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 81,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 81,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 81,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 84,
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
                  'variable' => 'resolutionArray',
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
                          'value' => 'x',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 84,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 84,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'resolution',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 84,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 84,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 84,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 84,
                  'char' => 53,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'equalWidth',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resolutionArray',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 85,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 85,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 85,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 85,
                  'char' => 44,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'equalHeight',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resolutionArray',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 86,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 86,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 86,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 86,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 88,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'resolution',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 88,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 88,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 88,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                'line' => 88,
                'char' => 39,
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
                      'variable' => 'resolution',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'resolution',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 89,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 89,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 89,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 89,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 92,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'width',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 92,
                    'char' => 19,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'equalWidth',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 92,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 92,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'height',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 92,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'equalHeight',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 92,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 92,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                'line' => 92,
                'char' => 57,
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
                      'variable' => 'replacePairs',
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
                              'value' => ':resolution',
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                              'line' => 94,
                              'char' => 29,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'resolution',
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                              'line' => 95,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                            'line' => 95,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 95,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 95,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 97,
                  'char' => 22,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                      'line' => 97,
                      'char' => 24,
                    ),
                    'name' => 'appendMessage',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                            'line' => 98,
                            'char' => 22,
                          ),
                          'name' => 'messageFactory',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'validation',
                                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                                'line' => 98,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                              'line' => 98,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                                'line' => 98,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                              'line' => 98,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                                'line' => 98,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                              'line' => 98,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                          'line' => 99,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                        'line' => 99,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 99,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 101,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                    'line' => 101,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                  'line' => 102,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 104,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                'line' => 104,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Executes the validation
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
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
                'line' => 64,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
            'line' => 64,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
          'line' => 63,
          'last-line' => 106,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
      'line' => 56,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Equal.zep',
    'line' => 56,
    'char' => 5,
  ),
);