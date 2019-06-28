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
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator\\StringLength',
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
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
        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
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
        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
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
        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
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
        'name' => 'Phalcon\\Validation\\Exception',
        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
    'line' => 63,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Validates that a string has the specified maximum constraints
 * The test is passed if for a string\'s length L, L<=max, i.e. L must
 * be at most max.
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\StringLength\\Max;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new Max(
 *         [
 *             "max"      => 50,
 *             "message"  => "We don\'t like really long names",
 *             "included" => true
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new Max(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "message" => [
 *                 "name_last"  => "We don\'t like really long last names",
 *                 "name_first" => "We don\'t like really long first names",
 *             ],
 *             "included" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
    'line' => 64,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Max',
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
            'value' => 'Field :field must not exceed :max characters long',
            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
            'line' => 66,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
          'line' => 70,
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
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 71,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 71,
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
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 71,
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
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 73,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'length',
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 73,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'maximum',
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 73,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 73,
                  'char' => 49,
                ),
                4 => 
                array (
                  'variable' => 'included',
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 73,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 73,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 75,
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
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 75,
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
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 75,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 75,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 75,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 75,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 78,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'mb_strlen',
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 78,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 78,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 78,
                'char' => 39,
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
                      'variable' => 'length',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'mb_strlen',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                              'line' => 79,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                            'line' => 79,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 79,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 79,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 80,
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
                      'variable' => 'length',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strlen',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                              'line' => 81,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                            'line' => 81,
                            'char' => 38,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 81,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 81,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 84,
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
                  'variable' => 'maximum',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 84,
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
                          'value' => 'max',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 84,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 84,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 84,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 84,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 86,
              'char' => 10,
            ),
            4 => 
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
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 86,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 86,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 86,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 86,
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
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 87,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 87,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 87,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 87,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 90,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'included',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 90,
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
                          'value' => 'included',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 90,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 90,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 90,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 90,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 92,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'included',
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 92,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 92,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 92,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 92,
                'char' => 37,
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
                      'variable' => 'included',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'included',
                            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                            'line' => 93,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                            'line' => 93,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 93,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 93,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 93,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 94,
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
                      'variable' => 'included',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'included',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 95,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 95,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 95,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 98,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'included',
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 98,
                'char' => 21,
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
                        'type' => 'greater-equal',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 99,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'maximum',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 99,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 99,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 99,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 100,
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
                        'type' => 'greater',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 101,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'maximum',
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 101,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 101,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 101,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 102,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 104,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 104,
                'char' => 19,
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
                              'value' => ':max',
                              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                              'line' => 106,
                              'char' => 22,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'maximum',
                              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                              'line' => 107,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                            'line' => 107,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 107,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 107,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 109,
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
                      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                      'line' => 109,
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
                            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                            'line' => 110,
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
                                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                                'line' => 110,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                              'line' => 110,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                                'line' => 110,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                              'line' => 110,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                                'line' => 110,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                              'line' => 110,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                          'line' => 111,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                        'line' => 111,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 111,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 113,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                    'line' => 113,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                  'line' => 114,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 116,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 116,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
              'line' => 117,
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
                'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
                'line' => 72,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
            'line' => 72,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
          'line' => 71,
          'last-line' => 118,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
      'line' => 64,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength/Max.zep',
    'line' => 64,
    'char' => 5,
  ),
);