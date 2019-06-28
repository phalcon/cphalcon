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
    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
    'line' => 50,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Check for a valid numeric value
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Numericality;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "price",
 *     new Numericality(
 *         [
 *             "message" => ":field is not numeric",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "price",
 *         "amount",
 *     ],
 *     new Numericality(
 *         [
 *             "message" => [
 *                 "price"  => "price is not numeric",
 *                 "amount" => "amount is not numeric",
 *             ]
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
    'line' => 51,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Numericality',
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
            'value' => 'Field :field does not have a valid numeric format',
            'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
            'line' => 53,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
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
                'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                'line' => 58,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
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
              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
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
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 60,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
              'line' => 61,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 61,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                      'line' => 64,
                      'char' => 34,
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
                          'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                          'line' => 64,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                        'line' => 64,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                    'line' => 64,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 64,
                  'char' => 50,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                      'line' => 65,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                    'line' => 65,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 65,
                  'char' => 37,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'str_replace',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => ' ',
                          'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                          'line' => 66,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                        'line' => 66,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                          'line' => 66,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                        'line' => 66,
                        'char' => 38,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                          'line' => 66,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                        'line' => 66,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                    'line' => 66,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 66,
                  'char' => 46,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'pattern',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '/((^[-]?[0-9,]+(.[0-9]+)?$)|(^[-]?[0-9.]+(,[0-9]+)?$))/',
                    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                    'line' => 67,
                    'char' => 78,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 67,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
              'line' => 69,
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
                        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                        'line' => 69,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                      'line' => 69,
                      'char' => 31,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                        'line' => 69,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                      'line' => 69,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 69,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                'line' => 69,
                'char' => 40,
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
                      'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                      'line' => 70,
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
                            'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                            'line' => 71,
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
                                'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                                'line' => 71,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                              'line' => 71,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                                'line' => 71,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                              'line' => 71,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                          'line' => 72,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                        'line' => 72,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                    'line' => 72,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 74,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                    'line' => 74,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                  'line' => 75,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
              'line' => 77,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                'line' => 77,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
              'line' => 78,
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
                'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
                'line' => 59,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
          'line' => 58,
          'last-line' => 79,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
      'line' => 51,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Numericality.zep',
    'line' => 51,
    'char' => 5,
  ),
);