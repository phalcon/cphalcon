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
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
        'line' => 15,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
        'line' => 16,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
    'line' => 56,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks that two values have the same value
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Confirmation;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "password",
 *     new Confirmation(
 *         [
 *             "message" => "Password doesn\'t match confirmation",
 *             "with"    => "confirmPassword",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "password",
 *         "email",
 *     ],
 *     new Confirmation(
 *         [
 *             "message" => [
 *                 "password" => "Password doesn\'t match confirmation",
 *                 "email"    => "Email doesn\'t match confirmation",
 *             ],
 *             "with" => [
 *                 "password" => "confirmPassword",
 *                 "email"    => "confirmEmail",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
    'line' => 57,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Confirmation',
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
            'value' => 'Field :field must be the same as :with',
            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
            'line' => 59,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                'line' => 64,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
                  'variable' => 'fieldWith',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 66,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 66,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'valueWith',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 66,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'labelWith',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 66,
                  'char' => 51,
                ),
                4 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 66,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
                  'variable' => 'fieldWith',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 68,
                      'char' => 30,
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
                          'value' => 'with',
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 68,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 68,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 68,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 68,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 70,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'fieldWith',
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 70,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 70,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 70,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                'line' => 70,
                'char' => 38,
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
                      'variable' => 'fieldWith',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fieldWith',
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 71,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 71,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 71,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 71,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 72,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 74,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 74,
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
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 74,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 74,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 74,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 74,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'valueWith',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 75,
                      'char' => 36,
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
                          'value' => 'fieldWith',
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 75,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 75,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 75,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 75,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 77,
              'char' => 10,
            ),
            4 => 
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
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 77,
                    'char' => 18,
                  ),
                  'name' => 'compare',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 77,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 77,
                      'char' => 32,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'valueWith',
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 77,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 77,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 77,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
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
                      'variable' => 'labelWith',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 78,
                          'char' => 34,
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
                              'value' => 'labelWith',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 78,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 78,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 78,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 78,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 80,
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
                        'value' => 'labelWith',
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 80,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 80,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 80,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 80,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'labelWith',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'labelWith',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 81,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'fieldWith',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 81,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 81,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 81,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 82,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 84,
                  'char' => 14,
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
                      'value' => 'labelWith',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 84,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 84,
                    'char' => 32,
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
                          'variable' => 'labelWith',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validation',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 85,
                              'char' => 44,
                            ),
                            'name' => 'getLabel',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fieldWith',
                                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                                  'line' => 85,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                                'line' => 85,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 85,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 85,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 86,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 88,
                  'char' => 15,
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
                              'value' => ':with',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 89,
                              'char' => 22,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'labelWith',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 90,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 90,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 90,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 90,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 92,
                  'char' => 22,
                ),
                4 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 92,
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
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 93,
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
                                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                                'line' => 93,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 93,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                                'line' => 93,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 93,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                                'line' => 93,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 93,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                          'line' => 94,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 94,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 94,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 96,
                  'char' => 18,
                ),
                5 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 96,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 97,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 99,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                'line' => 99,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 100,
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
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                'line' => 65,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
            'line' => 65,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
          'line' => 64,
          'last-line' => 104,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'compare',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'a',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 105,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'b',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 105,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 107,
                  'char' => 17,
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
                      'value' => 'ignoreCase',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 107,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 107,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 107,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 107,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                'line' => 107,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
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
                              'value' => 'mb_strtolower',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 111,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 111,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 111,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 111,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                    'line' => 111,
                    'char' => 57,
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
                              'value' => 'Extension \'mbstring\' is required',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 112,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 112,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 112,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 113,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 115,
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
                      'variable' => 'a',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'mb_strtolower',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'a',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 115,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 115,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'utf-8',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 115,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 115,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 115,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 115,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 116,
                  'char' => 15,
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
                      'variable' => 'b',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'mb_strtolower',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'b',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 116,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 116,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'utf-8',
                              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                              'line' => 116,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                            'line' => 116,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                        'line' => 116,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                      'line' => 116,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 117,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 119,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'a',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 119,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'b',
                  'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                  'line' => 119,
                  'char' => 22,
                ),
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                'line' => 119,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
              'line' => 120,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Compare strings
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
                'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
                'line' => 106,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
            'line' => 106,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
          'line' => 105,
          'last-line' => 121,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
      'line' => 57,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Confirmation.zep',
    'line' => 57,
    'char' => 5,
  ),
);