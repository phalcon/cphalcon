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
    'file' => '/app/phalcon/Validation/Validator/Url.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Url.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Url.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Url.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Url.zep',
    'line' => 50,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Checks if a value has a url format
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Url as UrlValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "url",
 *     new UrlValidator(
 *         [
 *             "message" => ":field must be a url",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "url",
 *         "homepage",
 *     ],
 *     new UrlValidator(
 *         [
 *             "message" => [
 *                 "url"      => "url must be a url",
 *                 "homepage" => "homepage must be a url",
 *             ]
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Url.zep',
    'line' => 51,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Url',
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
            'value' => 'Field :field must be a url',
            'file' => '/app/phalcon/Validation/Validator/Url.zep',
            'line' => 53,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
                'file' => '/app/phalcon/Validation/Validator/Url.zep',
                'line' => 58,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
              'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
                  'variable' => 'options',
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 60,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 60,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 60,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
                      'file' => '/app/phalcon/Validation/Validator/Url.zep',
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
                          'file' => '/app/phalcon/Validation/Validator/Url.zep',
                          'line' => 62,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Url.zep',
                        'line' => 62,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Url.zep',
                    'line' => 62,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 62,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Url.zep',
              'line' => 64,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'options',
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 64,
                  'char' => 50,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Url.zep',
                      'line' => 64,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Validation/Validator/Url.zep',
                      'line' => 64,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Url.zep',
                    'line' => 64,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'options',
                    'file' => '/app/phalcon/Validation/Validator/Url.zep',
                    'line' => 64,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 64,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Validation/Validator/Url.zep',
                'line' => 64,
                'char' => 50,
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
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'filter_var',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Validation/Validator/Url.zep',
                              'line' => 65,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Url.zep',
                            'line' => 65,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'FILTER_VALIDATE_URL',
                              'file' => '/app/phalcon/Validation/Validator/Url.zep',
                              'line' => 65,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Url.zep',
                            'line' => 65,
                            'char' => 63,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Validation/Validator/Url.zep',
                              'line' => 65,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Url.zep',
                            'line' => 65,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Url.zep',
                        'line' => 65,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Url.zep',
                      'line' => 65,
                      'char' => 73,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 66,
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
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'filter_var',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Validation/Validator/Url.zep',
                              'line' => 67,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Url.zep',
                            'line' => 67,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'FILTER_VALIDATE_URL',
                              'file' => '/app/phalcon/Validation/Validator/Url.zep',
                              'line' => 67,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Url.zep',
                            'line' => 67,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Url.zep',
                        'line' => 67,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Url.zep',
                      'line' => 67,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 68,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Url.zep',
              'line' => 70,
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
                  'value' => 'result',
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 70,
                  'char' => 20,
                ),
                'file' => '/app/phalcon/Validation/Validator/Url.zep',
                'line' => 70,
                'char' => 20,
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
                      'file' => '/app/phalcon/Validation/Validator/Url.zep',
                      'line' => 71,
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
                            'file' => '/app/phalcon/Validation/Validator/Url.zep',
                            'line' => 72,
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
                                'file' => '/app/phalcon/Validation/Validator/Url.zep',
                                'line' => 72,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Url.zep',
                              'line' => 72,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Url.zep',
                                'line' => 72,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Url.zep',
                              'line' => 72,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Url.zep',
                          'line' => 73,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Url.zep',
                        'line' => 73,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Url.zep',
                    'line' => 73,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 75,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Url.zep',
                    'line' => 75,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Url.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Url.zep',
              'line' => 78,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Url.zep',
                'line' => 78,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Url.zep',
              'line' => 79,
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
                'file' => '/app/phalcon/Validation/Validator/Url.zep',
                'line' => 59,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Url.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Url.zep',
          'line' => 58,
          'last-line' => 80,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Url.zep',
      'line' => 51,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Url.zep',
    'line' => 51,
    'char' => 5,
  ),
);