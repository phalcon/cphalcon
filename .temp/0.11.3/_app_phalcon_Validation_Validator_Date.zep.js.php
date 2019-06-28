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
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
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
        'name' => 'DateTime',
        'file' => '/app/phalcon/Validation/Validator/Date.zep',
        'line' => 13,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
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
        'name' => 'Phalcon\\Messages\\Message',
        'file' => '/app/phalcon/Validation/Validator/Date.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
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
        'name' => 'Phalcon\\Validation\\Validation',
        'file' => '/app/phalcon/Validation/Validator/Date.zep',
        'line' => 15,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
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
        'name' => 'Phalcon\\Validation\\AbstractValidator',
        'file' => '/app/phalcon/Validation/Validator/Date.zep',
        'line' => 16,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
    'line' => 56,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks if a value is a valid date
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Date as DateValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "date",
 *     new DateValidator(
 *         [
 *             "format"  => "d-m-Y",
 *             "message" => "The date is invalid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "date",
 *         "anotherDate",
 *     ],
 *     new DateValidator(
 *         [
 *             "format" => [
 *                 "date"        => "d-m-Y",
 *                 "anotherDate" => "Y-m-d",
 *             ],
 *             "message" => [
 *                 "date"        => "The date is invalid",
 *                 "anotherDate" => "The another date is invalid",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
    'line' => 57,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Date',
    'abstract' => 0,
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
          'name' => 'template',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Field :field is not a valid date',
            'file' => '/app/phalcon/Validation/Validator/Date.zep',
            'line' => 59,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Validation/Validator/Date.zep',
          'line' => 63,
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
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 64,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 64,
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
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 64,
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 66,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'format',
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 66,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 68,
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
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 68,
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
                          'file' => '/app/phalcon/Validation/Validator/Date.zep',
                          'line' => 68,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 68,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 68,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 68,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 69,
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
                  'variable' => 'format',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 69,
                      'char' => 27,
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
                          'value' => 'format',
                          'file' => '/app/phalcon/Validation/Validator/Date.zep',
                          'line' => 69,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 69,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 69,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 69,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 71,
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
                    'value' => 'format',
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 71,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 71,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 71,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 71,
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
                      'variable' => 'format',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'format',
                          'file' => '/app/phalcon/Validation/Validator/Date.zep',
                          'line' => 72,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Date.zep',
                          'line' => 72,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 72,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 72,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 73,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 75,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'format',
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 75,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 75,
                'char' => 25,
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
                      'variable' => 'format',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'Y-m-d',
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 76,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 76,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 79,
              'char' => 10,
            ),
            5 => 
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
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 79,
                    'char' => 18,
                  ),
                  'name' => 'checkDate',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 79,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 79,
                      'char' => 34,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'format',
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 79,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 79,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 79,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 79,
                'char' => 44,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 80,
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
                            'file' => '/app/phalcon/Validation/Validator/Date.zep',
                            'line' => 81,
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
                                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                                'line' => 81,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Date.zep',
                              'line' => 81,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                                'line' => 81,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Date.zep',
                              'line' => 81,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Date.zep',
                          'line' => 82,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 82,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 82,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 84,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 84,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 85,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 87,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 87,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 88,
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
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 65,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Date.zep',
            'line' => 65,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Date.zep',
          'line' => 64,
          'last-line' => 90,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkDate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 90,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'format',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 90,
              'char' => 45,
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
                  'variable' => 'date',
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 92,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'errors',
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 92,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 94,
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
                  'type' => 'fcall',
                  'name' => 'is_string',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 94,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 94,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 94,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 94,
                'char' => 30,
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
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 95,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 98,
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
                  'variable' => 'date',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'DateTime',
                    'dynamic' => 0,
                    'name' => 'createFromFormat',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'format',
                          'file' => '/app/phalcon/Validation/Validator/Date.zep',
                          'line' => 98,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 98,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/Date.zep',
                          'line' => 98,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Date.zep',
                        'line' => 98,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 98,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 98,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 99,
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
                  'variable' => 'errors',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'DateTime',
                    'dynamic' => 0,
                    'name' => 'getLastErrors',
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 99,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 99,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 101,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
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
                      'value' => 'errors',
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 101,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'warning_count',
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 101,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 101,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 101,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 101,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'errors',
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 101,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'error_count',
                      'file' => '/app/phalcon/Validation/Validator/Date.zep',
                      'line' => 101,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 101,
                    'char' => 67,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Validation/Validator/Date.zep',
                    'line' => 101,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Date.zep',
                  'line' => 101,
                  'char' => 70,
                ),
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 101,
                'char' => 70,
              ),
              'file' => '/app/phalcon/Validation/Validator/Date.zep',
              'line' => 102,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Validation/Validator/Date.zep',
                'line' => 91,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Date.zep',
            'line' => 91,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Date.zep',
          'line' => 90,
          'last-line' => 103,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Date.zep',
      'line' => 57,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Date.zep',
    'line' => 57,
    'char' => 5,
  ),
);