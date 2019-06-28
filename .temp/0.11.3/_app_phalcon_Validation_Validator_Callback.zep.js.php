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
    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
    'line' => 60,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Calls user function for validation
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Callback as CallbackValidator;
 * use Phalcon\\Validation\\Validator\\Numericality as NumericalityValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     ["user", "admin"],
 *     new CallbackValidator(
 *         [
 *             "message" => "There must be only an user or admin set",
 *             "callback" => function($data) {
 *                 if (!empty($data->getUser()) && !empty($data->getAdmin())) {
 *                     return false;
 *                 }
 *
 *                 return true;
 *             }
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     "amount",
 *     new CallbackValidator(
 *         [
 *             "callback" => function($data) {
 *                 if (!empty($data->getProduct())) {
 *                     return new NumericalityValidator(
 *                         [
 *                             "message" => "Amount must be a number."
 *                         ]
 *                     );
 *                 }
 *             }
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
    'line' => 61,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Callback',
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
            'value' => 'Field :field must match the callback function',
            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
            'line' => 63,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
          'line' => 67,
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
                'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                'line' => 68,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
              'line' => 68,
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
              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
              'line' => 68,
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
                  'variable' => 'callback',
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 70,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'returnedValue',
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 70,
                  'char' => 36,
                ),
                2 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 70,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
              'line' => 72,
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
                  'variable' => 'callback',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 72,
                      'char' => 29,
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
                          'value' => 'callback',
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 72,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 72,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                    'line' => 72,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 72,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
              'line' => 74,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_callable',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'callback',
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 74,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                    'line' => 74,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                'line' => 74,
                'char' => 34,
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validation',
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 75,
                          'char' => 35,
                        ),
                        'name' => 'getEntity',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 75,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 75,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 77,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 77,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                    'line' => 77,
                    'char' => 27,
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
                          'variable' => 'data',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validation',
                              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                              'line' => 78,
                              'char' => 39,
                            ),
                            'name' => 'getData',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 78,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 78,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 79,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 81,
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
                      'variable' => 'returnedValue',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'call_user_func',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'callback',
                              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                              'line' => 81,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 81,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                              'line' => 81,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 81,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 81,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 81,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 83,
                  'char' => 14,
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
                        'value' => 'returnedValue',
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 83,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 83,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'boolean',
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 83,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                    'line' => 83,
                    'char' => 48,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'returnedValue',
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 84,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 84,
                        'char' => 35,
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
                              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                              'line' => 85,
                              'char' => 32,
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
                                    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                    'line' => 86,
                                    'char' => 30,
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
                                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                        'line' => 86,
                                        'char' => 56,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                      'line' => 86,
                                      'char' => 56,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'field',
                                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                        'line' => 86,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                      'line' => 86,
                                      'char' => 63,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                  'line' => 87,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                'line' => 87,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 87,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 89,
                          'char' => 26,
                        ),
                        1 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 89,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 90,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 92,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 92,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 93,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'returnedValue',
                              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                              'line' => 93,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 93,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 93,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 93,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'instanceof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'returnedValue',
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 93,
                            'char' => 79,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Validator',
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 93,
                            'char' => 91,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 93,
                          'char' => 91,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 93,
                        'char' => 91,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'returnedValue',
                              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                              'line' => 94,
                              'char' => 38,
                            ),
                            'name' => 'validate',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'validation',
                                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                  'line' => 94,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                'line' => 94,
                                'char' => 58,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                  'line' => 94,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                                'line' => 94,
                                'char' => 65,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                            'line' => 94,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 95,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                      'line' => 97,
                      'char' => 17,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 97,
                  'char' => 17,
                ),
                4 => 
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
                          'value' => 'Callback must return bool or Phalcon\\\\Validation\\\\Validator object',
                          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                          'line' => 99,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                        'line' => 99,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                    'line' => 99,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                  'line' => 100,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
              'line' => 102,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                'line' => 102,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Callback.zep',
              'line' => 103,
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
                'file' => '/app/phalcon/Validation/Validator/Callback.zep',
                'line' => 69,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Callback.zep',
            'line' => 69,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Callback.zep',
          'line' => 68,
          'last-line' => 104,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Callback.zep',
      'line' => 61,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Callback.zep',
    'line' => 61,
    'char' => 5,
  ),
);