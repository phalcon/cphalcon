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
    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
    'line' => 55,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Allows validate if the value of a field matches a regular expression
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Regex as RegexValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "created_at",
 *     new RegexValidator(
 *         [
 *             "pattern" => "/^[0-9]{4}[-\\/](0[1-9]|1[12])[-\\/](0[1-9]|[12][0-9]|3[01])$/",
 *             "message" => "The creation date is invalid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "created_at",
 *         "name",
 *     ],
 *     new RegexValidator(
 *         [
 *             "pattern" => [
 *                 "created_at" => "/^[0-9]{4}[-\\/](0[1-9]|1[12])[-\\/](0[1-9]|[12][0-9]|3[01])$/",
 *                 "name"       => "/^[a-z]$/",
 *             ],
 *             "message" => [
 *                 "created_at" => "The creation date is invalid",
 *                 "name"       => "The name is invalid",
 *             ]
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
    'line' => 56,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Regex',
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
            'value' => 'Field :field does not match the required format',
            'file' => '/app/phalcon/Validation/Validator/Regex.zep',
            'line' => 58,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
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
                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                'line' => 63,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
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
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
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
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 65,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 65,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 65,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 66,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'failed',
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 66,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 70,
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
                  'variable' => 'matches',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 70,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 70,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 71,
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
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 71,
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
                          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                          'line' => 71,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                        'line' => 71,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 71,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 71,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 73,
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
                  'variable' => 'pattern',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 73,
                      'char' => 28,
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
                          'value' => 'pattern',
                          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                          'line' => 73,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                        'line' => 73,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 73,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 73,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 75,
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
                    'value' => 'pattern',
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 75,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 75,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 75,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                'line' => 75,
                'char' => 36,
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
                      'variable' => 'pattern',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pattern',
                          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                          'line' => 76,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                          'line' => 76,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                        'line' => 76,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 76,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 79,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
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
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 79,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 79,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 79,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 79,
                    'char' => 37,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'matches',
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 79,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 79,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                'line' => 79,
                'char' => 48,
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
                      'variable' => 'failed',
                      'expr' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'matches',
                            'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                            'line' => 80,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                            'line' => 80,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                          'line' => 80,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                          'line' => 80,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                        'line' => 80,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 80,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 81,
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
                      'variable' => 'failed',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                        'line' => 82,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 82,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 83,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 85,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'failed',
                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                'line' => 85,
                'char' => 19,
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
                      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                      'line' => 86,
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
                            'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                            'line' => 87,
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
                                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                                'line' => 87,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                              'line' => 87,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                                'line' => 87,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                              'line' => 87,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                          'line' => 88,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                        'line' => 88,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 88,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 90,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                    'line' => 90,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                  'line' => 91,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 93,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                'line' => 93,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Regex.zep',
              'line' => 94,
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
                'file' => '/app/phalcon/Validation/Validator/Regex.zep',
                'line' => 64,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Regex.zep',
            'line' => 64,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Regex.zep',
          'line' => 63,
          'last-line' => 95,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Regex.zep',
      'line' => 56,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Regex.zep',
    'line' => 56,
    'char' => 5,
  ),
);