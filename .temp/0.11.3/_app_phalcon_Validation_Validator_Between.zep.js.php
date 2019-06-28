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
    'file' => '/app/phalcon/Validation/Validator/Between.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Between.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Between.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Between.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Between.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Between.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Between.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Between.zep',
    'line' => 61,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Validates that a value is between an inclusive range of two values.
 * For a value x, the test is passed if minimum<=x<=maximum.
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Between;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "price",
 *     new Between(
 *         [
 *             "minimum" => 0,
 *             "maximum" => 100,
 *             "message" => "The price must be between 0 and 100",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "price",
 *         "amount",
 *     ],
 *     new Between(
 *         [
 *             "minimum" => [
 *                 "price"  => 0,
 *                 "amount" => 0,
 *             ],
 *             "maximum" => [
 *                 "price"  => 100,
 *                 "amount" => 50,
 *             ],
 *             "message" => [
 *                 "price"  => "The price must be between 0 and 100",
 *                 "amount" => "The amount must be between 0 and 50",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Between.zep',
    'line' => 62,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Between',
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
            'value' => 'Field :field must be within the range of :min to :max',
            'file' => '/app/phalcon/Validation/Validator/Between.zep',
            'line' => 64,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Validation/Validator/Between.zep',
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
                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                'line' => 69,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
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
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 71,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'minimum',
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 71,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'maximum',
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 71,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 71,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
              'line' => 73,
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
                      'file' => '/app/phalcon/Validation/Validator/Between.zep',
                      'line' => 73,
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
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 73,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Between.zep',
                        'line' => 73,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 73,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 73,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'minimum',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Between.zep',
                      'line' => 74,
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
                          'value' => 'minimum',
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 74,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Between.zep',
                        'line' => 74,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 74,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 74,
                  'char' => 47,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'maximum',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Between.zep',
                      'line' => 75,
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
                          'value' => 'maximum',
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 75,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Between.zep',
                        'line' => 75,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 75,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 75,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
              'line' => 77,
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
                    'value' => 'minimum',
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 77,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 77,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 77,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                'line' => 77,
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
                      'variable' => 'minimum',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'minimum',
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 78,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 78,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Between.zep',
                        'line' => 78,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Between.zep',
                      'line' => 78,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 79,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
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
                    'value' => 'maximum',
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 81,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 81,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 81,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                'line' => 81,
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
                      'variable' => 'maximum',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'maximum',
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 82,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 82,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Between.zep',
                        'line' => 82,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Between.zep',
                      'line' => 82,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 83,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
              'line' => 85,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'less',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 85,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'minimum',
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 85,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 85,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'greater',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 85,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'maximum',
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 85,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 85,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                'line' => 85,
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
                              'value' => ':min',
                              'file' => '/app/phalcon/Validation/Validator/Between.zep',
                              'line' => 87,
                              'char' => 21,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'minimum',
                              'file' => '/app/phalcon/Validation/Validator/Between.zep',
                              'line' => 87,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Between.zep',
                            'line' => 87,
                            'char' => 32,
                          ),
                          1 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => ':max',
                              'file' => '/app/phalcon/Validation/Validator/Between.zep',
                              'line' => 88,
                              'char' => 21,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'maximum',
                              'file' => '/app/phalcon/Validation/Validator/Between.zep',
                              'line' => 89,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Between.zep',
                            'line' => 89,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Between.zep',
                        'line' => 89,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Between.zep',
                      'line' => 89,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 91,
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
                      'file' => '/app/phalcon/Validation/Validator/Between.zep',
                      'line' => 91,
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
                            'file' => '/app/phalcon/Validation/Validator/Between.zep',
                            'line' => 92,
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
                                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                                'line' => 92,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Between.zep',
                              'line' => 92,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                                'line' => 92,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Between.zep',
                              'line' => 92,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                                'line' => 92,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Between.zep',
                              'line' => 92,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Between.zep',
                          'line' => 93,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Between.zep',
                        'line' => 93,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 93,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 95,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Between.zep',
                    'line' => 95,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Between.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
              'line' => 98,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                'line' => 98,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Between.zep',
              'line' => 99,
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
                'file' => '/app/phalcon/Validation/Validator/Between.zep',
                'line' => 70,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Between.zep',
            'line' => 70,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Between.zep',
          'line' => 69,
          'last-line' => 100,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Between.zep',
      'line' => 62,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Between.zep',
    'line' => 62,
    'char' => 5,
  ),
);