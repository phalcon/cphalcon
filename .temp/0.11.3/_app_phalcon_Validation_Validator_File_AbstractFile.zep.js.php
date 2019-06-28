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
    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator\\File',
    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
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
        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
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
        'name' => 'Phalcon\\Validation\\AbstractValidator',
        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
    'line' => 55,
    'char' => 2,
  ),
  5 => 
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
 *     new Size(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max filesize (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new FileValidator(
 *         [
 *             "maxSize" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "messageSize" => [
 *                 "file"        => "file exceeds the max filesize 2M",
 *                 "anotherFile" => "anotherFile exceeds the max filesize 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
    'line' => 56,
    'char' => 8,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'AbstractFile',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'AbstractValidator',
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
          'name' => 'messageFileEmpty',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Field :field must not be empty',
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 61,
            'char' => 65,
          ),
          'docblock' => '**
    * Empty is empty
    *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 61,
              'char' => 70,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 61,
              'char' => 76,
            ),
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 65,
          'char' => 5,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'messageIniSize',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'File :field exceeds the maximum file size',
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 66,
            'char' => 74,
          ),
          'docblock' => '**
    * File exceeed the file size setted in PHP configuration
    *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 66,
              'char' => 79,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 66,
              'char' => 85,
            ),
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 70,
          'char' => 5,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'messageValid',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Field :field is not valid',
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 71,
            'char' => 56,
          ),
          'docblock' => '**
    * File is not valid
    *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 71,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 71,
              'char' => 67,
            ),
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 79,
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
          'name' => 'isAllowEmpty',
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 80,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 80,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 80,
              'char' => 72,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 82,
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
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 82,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 82,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 82,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 82,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 84,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 84,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 84,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'and',
                  'left' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 84,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'error',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 84,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 84,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 84,
                    'char' => 51,
                  ),
                  'right' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 84,
                        'char' => 58,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'error',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 84,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 84,
                      'char' => 68,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'UPLOAD_ERR_NO_FILE',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 84,
                      'char' => 88,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 84,
                    'char' => 88,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 84,
                  'char' => 88,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 84,
                'char' => 88,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 85,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check on empty
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 81,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 80,
          'last-line' => 93,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'checkUpload',
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 94,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 94,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 94,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'and',
                  'left' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 96,
                      'char' => 21,
                    ),
                    'name' => 'checkUploadMaxSize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validation',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 96,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 96,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 96,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 96,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 96,
                    'char' => 61,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 97,
                      'char' => 21,
                    ),
                    'name' => 'checkUploadIsEmpty',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validation',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 97,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 97,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 97,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 97,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 97,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 97,
                  'char' => 61,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 98,
                    'char' => 21,
                  ),
                  'name' => 'checkUploadIsValid',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'validation',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 98,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 98,
                      'char' => 51,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 98,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 98,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 98,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 98,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 99,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Check upload
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 95,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 94,
          'last-line' => 107,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'checkUploadMaxSize',
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 108,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 108,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 108,
              'char' => 74,
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
                  'variable' => 'label',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 110,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 110,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 110,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 112,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 112,
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
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 112,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 112,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 112,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 112,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 115,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'and',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '_SERVER',
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 115,
                            'char' => 19,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'REQUEST_METHOD',
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 115,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 115,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'POST',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 115,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 115,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => '_POST',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 116,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 116,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 116,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_FILES',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 117,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 117,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 117,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 118,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'CONTENT_LENGTH',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 118,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 118,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 118,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 118,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 118,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'and',
                  'left' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 119,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'error',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 119,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 119,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 119,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 119,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'error',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 119,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 119,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'UPLOAD_ERR_INI_SIZE',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 120,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 120,
                    'char' => 9,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 120,
                  'char' => 9,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 120,
                'char' => 9,
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
                      'variable' => 'label',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 121,
                          'char' => 30,
                        ),
                        'name' => 'prepareLabel',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validation',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 121,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 121,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 121,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 121,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 121,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 121,
                      'char' => 62,
                    ),
                    1 => 
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
                              'value' => ':field',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 123,
                              'char' => 27,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'label',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 124,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 124,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 124,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 124,
                      'char' => 18,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 126,
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
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 126,
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
                          'type' => 'new',
                          'class' => 'Message',
                          'dynamic' => 0,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'strtr',
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
                                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                        'line' => 128,
                                        'char' => 32,
                                      ),
                                      'name' => 'getMessageIniSize',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 128,
                                      'char' => 52,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 128,
                                    'char' => 52,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'replacePairs',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 128,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 128,
                                    'char' => 66,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 128,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 128,
                              'char' => 67,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 129,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 129,
                              'char' => 26,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'get_class',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 130,
                                      'char' => 35,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 130,
                                    'char' => 35,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 130,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 130,
                              'char' => 36,
                            ),
                            3 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                  'line' => 131,
                                  'char' => 26,
                                ),
                                'name' => 'prepareCode',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 131,
                                      'char' => 44,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 131,
                                    'char' => 44,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 132,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 132,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 133,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 133,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 133,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 135,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 135,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 136,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 138,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 138,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 139,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Check if uploaded file is larger than PHP allowed size
    *
    * @param Valiation $validation
    * @param mixed $field
    * @return boolean
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 108,
          'last-line' => 147,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'checkUploadIsEmpty',
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 148,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 148,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 148,
              'char' => 74,
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
                  'variable' => 'label',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 150,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 150,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 150,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 152,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 152,
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
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 152,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 152,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 152,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 152,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 154,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'or',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 154,
                            'char' => 24,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'error',
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 154,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 154,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 154,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 154,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 154,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'tmp_name',
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 154,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 154,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 154,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 154,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 154,
                    'char' => 59,
                  ),
                  'right' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 154,
                        'char' => 66,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'error',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 154,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 154,
                      'char' => 76,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'UPLOAD_ERR_OK',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 154,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 154,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 154,
                  'char' => 93,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'is_uploaded_file',
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
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 154,
                            'char' => 118,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'tmp_name',
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 154,
                            'char' => 127,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 154,
                          'char' => 128,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 154,
                        'char' => 128,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 154,
                    'char' => 130,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 154,
                  'char' => 130,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 154,
                'char' => 130,
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
                      'variable' => 'label',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 155,
                          'char' => 30,
                        ),
                        'name' => 'prepareLabel',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validation',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 155,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 155,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 155,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 155,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 155,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 155,
                      'char' => 62,
                    ),
                    1 => 
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
                              'value' => ':field',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 157,
                              'char' => 27,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'label',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 158,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 158,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 158,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 158,
                      'char' => 18,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 160,
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
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 160,
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
                          'type' => 'new',
                          'class' => 'Message',
                          'dynamic' => 0,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'strtr',
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
                                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                        'line' => 162,
                                        'char' => 32,
                                      ),
                                      'name' => 'getMessageFileEmpty',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 162,
                                      'char' => 54,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 162,
                                    'char' => 54,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'replacePairs',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 162,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 162,
                                    'char' => 68,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 162,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 162,
                              'char' => 69,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 163,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 163,
                              'char' => 26,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'get_class',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 164,
                                      'char' => 35,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 164,
                                    'char' => 35,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 164,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 164,
                              'char' => 36,
                            ),
                            3 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                  'line' => 165,
                                  'char' => 26,
                                ),
                                'name' => 'prepareCode',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 165,
                                      'char' => 44,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 165,
                                    'char' => 44,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 166,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 166,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 167,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 167,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 167,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 169,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 169,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 170,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 172,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 172,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 173,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Check if upload is empty
    *
    * @param Valiation $validation
    * @param mixed $field
    * @return boolean
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 149,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 149,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 148,
          'last-line' => 181,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'checkUploadIsValid',
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 182,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 182,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 182,
              'char' => 74,
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
                  'variable' => 'label',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 184,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 184,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 184,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 186,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 186,
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
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 186,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 186,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 186,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 186,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 188,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'or',
                  'left' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 188,
                          'char' => 24,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 188,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 188,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 188,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 188,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 188,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 188,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 188,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 188,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 188,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 188,
                  'char' => 54,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 188,
                        'char' => 68,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'size',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 188,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 188,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 188,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 188,
                  'char' => 75,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 188,
                'char' => 75,
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
                      'variable' => 'label',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 189,
                          'char' => 30,
                        ),
                        'name' => 'prepareLabel',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validation',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 189,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 189,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 189,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 189,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 189,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 189,
                      'char' => 62,
                    ),
                    1 => 
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
                              'value' => ':field',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 191,
                              'char' => 27,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'label',
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 192,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                            'line' => 192,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 192,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 192,
                      'char' => 18,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 194,
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
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 194,
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
                          'type' => 'new',
                          'class' => 'Message',
                          'dynamic' => 0,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'strtr',
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
                                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                        'line' => 196,
                                        'char' => 32,
                                      ),
                                      'name' => 'getMessageValid',
                                      'call-type' => 1,
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 196,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 196,
                                    'char' => 50,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'replacePairs',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 196,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 196,
                                    'char' => 64,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 196,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 196,
                              'char' => 65,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 197,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 197,
                              'char' => 26,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'get_class',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 198,
                                      'char' => 35,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 198,
                                    'char' => 35,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 198,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 198,
                              'char' => 36,
                            ),
                            3 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                  'line' => 199,
                                  'char' => 26,
                                ),
                                'name' => 'prepareCode',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 199,
                                      'char' => 44,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 199,
                                    'char' => 44,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 200,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 200,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 201,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 201,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 201,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 203,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 203,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 204,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 206,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 206,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 207,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Check if upload is valid
    *
    * @param Valiation $validation
    * @param mixed $field
    * @return boolean
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
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 183,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 183,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 182,
          'last-line' => 214,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFileSizeInBytes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'size',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 215,
              'char' => 52,
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
                  'variable' => 'byteUnits',
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
                          'value' => 'B',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 218,
                          'char' => 14,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 218,
                          'char' => 17,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 218,
                        'char' => 17,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'K',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 219,
                          'char' => 14,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '10',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 219,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 219,
                        'char' => 18,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'M',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 220,
                          'char' => 14,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '20',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 220,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 220,
                        'char' => 18,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'G',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 221,
                          'char' => 14,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '30',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 221,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 221,
                        'char' => 18,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'T',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 222,
                          'char' => 14,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '40',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 222,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 222,
                        'char' => 18,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'KB',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 223,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '10',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 223,
                          'char' => 19,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 223,
                        'char' => 19,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'MB',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 224,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '20',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 224,
                          'char' => 19,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 224,
                        'char' => 19,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'GB',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 225,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '30',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 225,
                          'char' => 19,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 225,
                        'char' => 19,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'TB',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 226,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '40',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 227,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 227,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 227,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 227,
                  'char' => 10,
                ),
                1 => 
                array (
                  'variable' => 'unit',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'B',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 227,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 227,
                  'char' => 20,
                ),
                2 => 
                array (
                  'variable' => 'matches',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 227,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 227,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 229,
              'char' => 18,
            ),
            1 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'preg_match',
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
                          'value' => '/^([0-9]+(?:\\\\.[0-9]+)?)(',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 230,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'implode',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '|',
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 230,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 230,
                              'char' => 50,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'array_keys',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'byteUnits',
                                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                      'line' => 230,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                    'line' => 230,
                                    'char' => 72,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                                'line' => 230,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                              'line' => 230,
                              'char' => 73,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 230,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 230,
                        'char' => 75,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ')?$/Di',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 230,
                        'char' => 83,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 230,
                      'char' => 83,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 230,
                    'char' => 83,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'size',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 231,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 231,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'matches',
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 233,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 233,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 233,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 235,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'matches',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 235,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '2',
                    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                    'line' => 235,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 235,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 235,
                'char' => 29,
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
                      'variable' => 'unit',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'matches',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 236,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 236,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 236,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 236,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 237,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 239,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mul',
                'left' => 
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
                          'value' => 'matches',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 239,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 239,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 239,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 239,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 239,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'pow',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'int',
                        'value' => '2',
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 239,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 239,
                      'char' => 44,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'byteUnits',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 239,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'unit',
                          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                          'line' => 239,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                        'line' => 239,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                      'line' => 239,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                  'line' => 239,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 239,
                'char' => 62,
              ),
              'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
              'line' => 240,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Convert a string like "2.5MB" in bytes
    *
    * @param string $size
    * @return float
    *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'double',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
                'line' => 216,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
            'line' => 216,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
          'line' => 215,
          'last-line' => 241,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
      'line' => 56,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Validation/Validator/File/AbstractFile.zep',
    'line' => 56,
    'char' => 14,
  ),
);