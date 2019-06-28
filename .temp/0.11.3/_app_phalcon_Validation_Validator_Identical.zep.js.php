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
    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
    'line' => 55,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks if a value is identical to other
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Identical;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "terms",
 *     new Identical(
 *         [
 *             "accepted" => "yes",
 *             "message" => "Terms and conditions must be accepted",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "terms",
 *         "anotherTerms",
 *     ],
 *     new Identical(
 *         [
 *             "accepted" => [
 *                 "terms"        => "yes",
 *                 "anotherTerms" => "yes",
 *             ],
 *             "message" => [
 *                 "terms"        => "Terms and conditions must be accepted",
 *                 "anotherTerms" => "Another terms  must be accepted",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
    'line' => 56,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Identical',
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
            'value' => 'Field :field does not have the expected value',
            'file' => '/app/phalcon/Validation/Validator/Identical.zep',
            'line' => 58,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                'line' => 63,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 65,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'accepted',
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 65,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
                  'variable' => 'valid',
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 66,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
              'line' => 68,
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
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 68,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                        'line' => 68,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                    'line' => 68,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 68,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
              'line' => 70,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 70,
                  'char' => 17,
                ),
                'name' => 'hasOption',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'accepted',
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 70,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                    'line' => 70,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
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
                      'variable' => 'accepted',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 71,
                          'char' => 33,
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
                              'value' => 'accepted',
                              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                              'line' => 71,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                            'line' => 71,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                        'line' => 71,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 71,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 72,
                  'char' => 9,
                ),
              ),
              'elseif_statements' => 
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
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 72,
                      'char' => 23,
                    ),
                    'name' => 'hasOption',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 72,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                        'line' => 72,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                    'line' => 72,
                    'char' => 41,
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
                          'variable' => 'accepted',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                              'line' => 73,
                              'char' => 33,
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
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                                  'line' => 73,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                                'line' => 73,
                                'char' => 49,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                            'line' => 73,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 73,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 74,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 76,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
              'line' => 76,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'accepted',
                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                'line' => 76,
                'char' => 21,
              ),
              'statements' => 
              array (
                0 => 
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
                        'value' => 'accepted',
                        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                        'line' => 77,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 77,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 77,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                    'line' => 77,
                    'char' => 41,
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
                          'variable' => 'accepted',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'accepted',
                              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                              'line' => 78,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                              'line' => 78,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                            'line' => 78,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 78,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 79,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 81,
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
                      'variable' => 'valid',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 81,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'accepted',
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 81,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                        'line' => 81,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 81,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
              'line' => 84,
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
                  'type' => 'variable',
                  'value' => 'valid',
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 84,
                  'char' => 19,
                ),
                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                'line' => 84,
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
                      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                      'line' => 85,
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
                            'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                            'line' => 86,
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
                                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                                'line' => 86,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                              'line' => 86,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                                'line' => 86,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                              'line' => 86,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                          'line' => 87,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                        'line' => 87,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                    'line' => 87,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 89,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                    'line' => 89,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
              'line' => 92,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                'line' => 92,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Identical.zep',
              'line' => 93,
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
                'file' => '/app/phalcon/Validation/Validator/Identical.zep',
                'line' => 64,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Identical.zep',
            'line' => 64,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Identical.zep',
          'line' => 63,
          'last-line' => 94,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Identical.zep',
      'line' => 56,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Identical.zep',
    'line' => 56,
    'char' => 5,
  ),
);