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
    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
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
        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
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
        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
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
        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
    'line' => 50,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks if a value has a valid credit card number
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\CreditCard as CreditCardValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "creditCard",
 *     new CreditCardValidator(
 *         [
 *             "message" => "The credit card number is not valid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "creditCard",
 *         "secondCreditCard",
 *     ],
 *     new CreditCardValidator(
 *         [
 *             "message" => [
 *                 "creditCard"       => "The credit card number is not valid",
 *                 "secondCreditCard" => "The second credit card number is not valid",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
    'line' => 51,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'CreditCard',
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
            'value' => 'Field :field is not valid for a credit card number',
            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
            'line' => 53,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
          'line' => 57,
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
                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                'line' => 58,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 58,
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
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 58,
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
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 60,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'valid',
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 60,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 62,
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
                      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                      'line' => 62,
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
                          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                          'line' => 62,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                        'line' => 62,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 62,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 62,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 64,
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
                  'variable' => 'valid',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                      'line' => 64,
                      'char' => 26,
                    ),
                    'name' => 'verifyByLuhnAlgorithm',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                          'line' => 64,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                        'line' => 64,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 64,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 64,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 66,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'valid',
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 66,
                  'char' => 19,
                ),
                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                'line' => 66,
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
                      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                      'line' => 67,
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
                            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                            'line' => 68,
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
                                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                                'line' => 68,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                              'line' => 68,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                                'line' => 68,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                              'line' => 68,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                          'line' => 69,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                        'line' => 69,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 69,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 71,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 71,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 72,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 74,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                'line' => 74,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 75,
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
                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                'line' => 59,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
          'line' => 58,
          'last-line' => 80,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'verifyByLuhnAlgorithm',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'number',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 81,
              'char' => 57,
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
                  'variable' => 'digit',
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 83,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'position',
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 83,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'hash',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 83,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 83,
                  'char' => 37,
                ),
                3 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 83,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 84,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'digits',
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 84,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
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
                  'variable' => 'digits',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'array',
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'str_split',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'number',
                            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                            'line' => 86,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                          'line' => 86,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                      'line' => 86,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 86,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 86,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 88,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'digits',
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 88,
                  'char' => 39,
                ),
                'name' => 'reversed',
                'call-type' => 1,
                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                'line' => 88,
                'char' => 51,
              ),
              'key' => 'position',
              'value' => 'digit',
              'reverse' => 0,
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
                      'variable' => 'hash',
                      'expr' => 
                      array (
                        'type' => 'list',
                        'left' => 
                        array (
                          'type' => 'ternary',
                          'left' => 
                          array (
                            'type' => 'mod',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'position',
                              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                              'line' => 89,
                              'char' => 34,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '2',
                              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                              'line' => 89,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                            'line' => 89,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'mul',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'digit',
                              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                              'line' => 89,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '2',
                              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                              'line' => 89,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                            'line' => 89,
                            'char' => 50,
                          ),
                          'extra' => 
                          array (
                            'type' => 'variable',
                            'value' => 'digit',
                            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                            'line' => 89,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                          'line' => 89,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                        'line' => 89,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                      'line' => 89,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 92,
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
                    'type' => 'fcall',
                    'name' => 'array_sum',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'str_split',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'hash',
                                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                                'line' => 93,
                                'char' => 27,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                              'line' => 93,
                              'char' => 27,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                          'line' => 94,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                        'line' => 94,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 94,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 94,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 96,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'list',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'mod',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'result',
                      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                      'line' => 96,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '10',
                      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                      'line' => 96,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 96,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                    'line' => 96,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                  'line' => 96,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                'line' => 96,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
              'line' => 97,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * is a simple checksum formula used to validate a variety of identification
     * numbers
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
                'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
                'line' => 82,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
            'line' => 82,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
          'line' => 81,
          'last-line' => 98,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
      'line' => 51,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/CreditCard.zep',
    'line' => 51,
    'char' => 5,
  ),
);