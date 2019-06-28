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
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator\\File',
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
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
        'name' => 'Phalcon\\Validation\\Exception',
        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
        'line' => 15,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
        'line' => 16,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
    'line' => 65,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks if a value has a correct file mime type
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\File\\MimeType;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new MimeType(
 *         [
 *             "types" => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "message" => "Allowed file types are :types"
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new MimeType(
 *         [
 *             "types" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "message" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ]
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
    'line' => 66,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'MimeType',
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
            'value' => 'File :field must be of type: :types',
            'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
            'line' => 68,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
          'line' => 76,
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
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 77,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 77,
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
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 77,
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
                  'variable' => 'fieldTypes',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 79,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'mime',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 79,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 79,
                  'char' => 43,
                ),
                3 => 
                array (
                  'variable' => 'tmp',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 79,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'types',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 79,
                  'char' => 55,
                ),
                5 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 79,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 82,
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
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 82,
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
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 82,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 82,
                      'char' => 40,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 82,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 82,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 82,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 82,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 82,
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
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 83,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 86,
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
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 86,
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
                          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                          'line' => 86,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 86,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 86,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 86,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 88,
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
                  'variable' => 'types',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 88,
                      'char' => 26,
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
                          'value' => 'types',
                          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                          'line' => 88,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 88,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 88,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 88,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 90,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'fieldTypes',
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 90,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'types',
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 90,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 90,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 90,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 90,
                'char' => 43,
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
                      'variable' => 'types',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'fieldTypes',
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 91,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 91,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 92,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 94,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'types',
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 94,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 94,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 94,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 94,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 94,
                'char' => 43,
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
                          'value' => 'Option \'allowedTypes\' must be an array',
                          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                          'line' => 97,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 97,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 97,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 100,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'function_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'finfo_open',
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 100,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 100,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 100,
                'char' => 40,
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
                      'variable' => 'tmp',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'finfo_open',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'FILEINFO_MIME_TYPE',
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 101,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                            'line' => 101,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 101,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 101,
                      'char' => 53,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'mime',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'finfo_file',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tmp',
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 102,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                            'line' => 102,
                            'char' => 38,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                'line' => 102,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'tmp_name',
                                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                'line' => 102,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 102,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                            'line' => 102,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 102,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 102,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 104,
                  'char' => 23,
                ),
                1 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'finfo_close',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tmp',
                          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                          'line' => 104,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 104,
                        'char' => 28,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 104,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 105,
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
                      'variable' => 'mime',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                          'line' => 106,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                          'line' => 106,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 106,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 106,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 107,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 109,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'in_array',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mime',
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 109,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 109,
                      'char' => 26,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'types',
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 109,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 109,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 109,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 109,
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
                              'value' => ':types',
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 111,
                              'char' => 23,
                            ),
                            'value' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'join',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ', ',
                                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                    'line' => 111,
                                    'char' => 32,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                  'line' => 111,
                                  'char' => 32,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'types',
                                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                    'line' => 111,
                                    'char' => 39,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                  'line' => 111,
                                  'char' => 39,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 112,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                            'line' => 112,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 112,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 112,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 114,
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
                      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                      'line' => 114,
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
                            'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                            'line' => 115,
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
                                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                'line' => 115,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 115,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                'line' => 115,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 115,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                                'line' => 115,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                              'line' => 115,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                          'line' => 116,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                        'line' => 116,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 116,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 118,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                    'line' => 118,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                  'line' => 119,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 121,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 121,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
              'line' => 122,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Executes the validation
     *
     * @param Valiation $validation
     * @param mixed $field
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
                'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
          'line' => 77,
          'last-line' => 123,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
      'line' => 66,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/File/MimeType.zep',
    'line' => 66,
    'char' => 5,
  ),
);