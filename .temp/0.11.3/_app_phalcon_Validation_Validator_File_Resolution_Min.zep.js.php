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
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator\\File\\Resolution',
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
        'line' => 15,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
    'line' => 60,
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
 * use Phalcon\\Validation\\Validator\\File\\Resolution\\Min;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Min(
 *         [
 *             "resolution" => "800x600",
 *             "message"    => "Min resolution of :field is :resolution",
 *             "included"   => true,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Min(
 *         [
 *             "resolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "Min resolution of file is 800x600",
 *                 "anotherFile" => "Min resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
    'line' => 61,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Min',
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
            'value' => 'File :field can not have the minimum resolution of :resolution',
            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
            'line' => 63,
            'char' => 88,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
          'line' => 67,
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
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 68,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 68,
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
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 68,
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
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 70,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'minHeight',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 70,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'minWidth',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 70,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'resolution',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 70,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'resolutionArray',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 70,
                  'char' => 69,
                ),
                5 => 
                array (
                  'variable' => 'tmp',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 71,
                  'char' => 16,
                ),
                6 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 71,
                  'char' => 23,
                ),
                7 => 
                array (
                  'variable' => 'width',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 71,
                  'char' => 30,
                ),
                8 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 71,
                  'char' => 44,
                ),
                9 => 
                array (
                  'variable' => 'included',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 71,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 71,
                  'char' => 62,
                ),
                10 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 71,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 74,
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
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 74,
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
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 74,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 74,
                      'char' => 40,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 74,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 74,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 74,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 74,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 74,
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
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 75,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 78,
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
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 78,
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
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 78,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 78,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 78,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 78,
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
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 79,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'tmp_name',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 79,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 79,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 79,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 79,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 79,
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
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 80,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 80,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 80,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 80,
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
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 81,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 81,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 81,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 81,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 83,
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
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 83,
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
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 83,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 83,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 83,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 83,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 85,
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
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 85,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 85,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 85,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 85,
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
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 86,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 86,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 86,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 86,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 87,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 89,
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
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 89,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 89,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'resolution',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 89,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 89,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 89,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 89,
                  'char' => 53,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'minWidth',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resolutionArray',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 90,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 90,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 90,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 90,
                  'char' => 42,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'minHeight',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resolutionArray',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 91,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 91,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 91,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 91,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 93,
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
                  'variable' => 'included',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 93,
                      'char' => 29,
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
                          'value' => 'included',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 93,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 93,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 93,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 93,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 95,
              'char' => 10,
            ),
            7 => 
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
                    'value' => 'included',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 95,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 95,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 95,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 95,
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
                      'variable' => 'included',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'included',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 96,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 96,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 96,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 96,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 96,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 97,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'variable' => 'included',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'included',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 98,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 98,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 98,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 99,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 101,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'included',
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 101,
                'char' => 21,
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
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'less-equal',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'width',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 102,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minWidth',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 102,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 102,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'less-equal',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'height',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 102,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minHeight',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 102,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 102,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 102,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 102,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 103,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'less',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'width',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 104,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minWidth',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 104,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 104,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'less',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'height',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 104,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'minHeight',
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 104,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 104,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 104,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 104,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 105,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 107,
              'char' => 10,
            ),
            9 => 
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
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 107,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 107,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 107,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 107,
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
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 108,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 108,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 108,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 108,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 109,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 111,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 111,
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
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                              'line' => 113,
                              'char' => 29,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'resolution',
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                              'line' => 114,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 114,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 114,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 114,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 116,
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
                      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                      'line' => 116,
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
                            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                            'line' => 117,
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
                                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                                'line' => 117,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                              'line' => 117,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                                'line' => 117,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                              'line' => 117,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                                'line' => 117,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                              'line' => 117,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                          'line' => 118,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                        'line' => 118,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 118,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 120,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                    'line' => 120,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                  'line' => 121,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 123,
              'char' => 14,
            ),
            11 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 123,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
              'line' => 124,
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
                'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
                'line' => 69,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
            'line' => 69,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
          'line' => 68,
          'last-line' => 125,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
      'line' => 61,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Resolution/Min.zep',
    'line' => 61,
    'char' => 5,
  ),
);