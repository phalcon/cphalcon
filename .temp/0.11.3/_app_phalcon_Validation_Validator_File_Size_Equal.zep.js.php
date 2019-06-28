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
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator\\File\\Size',
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
        'name' => 'Phalcon\\Validation\\Validator\\File\\Size\\Equal',
        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
        'line' => 15,
        'char' => 49,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
        'name' => 'Phalcon\\Validation\\Validator\\File\\AbstractFile',
        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
        'line' => 16,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
    'line' => 61,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\File\\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Equal(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the equal filesize (:size)",
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
 *             "size" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "file does not have the rigth filesize",
 *                 "anotherFile" => "anotherFile wrong filesize (4MB)",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
    'line' => 62,
    'char' => 5,
  ),
  7 => 
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
            'value' => 'File :field does not have the exact :size filesize',
            'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
            'line' => 64,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
          'line' => 68,
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
                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                'line' => 69,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
              'line' => 69,
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
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
              'line' => 69,
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
                  'variable' => 'bytes',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 71,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'fileSize',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 71,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 71,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'size',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 71,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 71,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 74,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                      'line' => 74,
                      'char' => 40,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 74,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                      'line' => 74,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 74,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 74,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 75,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
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
                      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                      'line' => 78,
                      'char' => 32,
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
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 78,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 78,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 78,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 78,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'size',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                      'line' => 79,
                      'char' => 25,
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
                          'value' => 'size',
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 79,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 79,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 79,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 79,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
              'line' => 81,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'size',
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 81,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 81,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 81,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                'line' => 81,
                'char' => 33,
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
                      'variable' => 'size',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'size',
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 82,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 82,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 82,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                      'line' => 82,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 83,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
              'line' => 85,
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
                  'variable' => 'bytes',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'round',
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
                            'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                            'line' => 85,
                            'char' => 32,
                          ),
                          'name' => 'getFileSizeInBytes',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'size',
                                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                                'line' => 85,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                              'line' => 85,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 85,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 85,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '6',
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 85,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 85,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 85,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 85,
                  'char' => 61,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'fileSize',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'round',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'floatval',
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
                                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                                  'line' => 86,
                                  'char' => 44,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                                  'line' => 86,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                                'line' => 86,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                              'line' => 86,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 86,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 86,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '6',
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 86,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 86,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 86,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 86,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
              'line' => 88,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'bytes',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 88,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'fileSize',
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 88,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                'line' => 88,
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
                              'value' => ':size',
                              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                              'line' => 90,
                              'char' => 24,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'size',
                              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                              'line' => 91,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                            'line' => 91,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 91,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                      'line' => 91,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 93,
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
                      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                      'line' => 93,
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
                            'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                            'line' => 94,
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
                                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                                'line' => 94,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                              'line' => 94,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                                'line' => 94,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                              'line' => 94,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                                'line' => 94,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                              'line' => 94,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                          'line' => 95,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                        'line' => 95,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 95,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 97,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                    'line' => 97,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
              'line' => 100,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                'line' => 100,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
              'line' => 101,
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
                'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
                'line' => 70,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
            'line' => 70,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
          'line' => 69,
          'last-line' => 102,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
      'line' => 62,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/File/Size/Equal.zep',
    'line' => 62,
    'char' => 5,
  ),
);