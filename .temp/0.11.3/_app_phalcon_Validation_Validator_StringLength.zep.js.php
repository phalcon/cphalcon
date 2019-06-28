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
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
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
        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
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
        'name' => 'Phalcon\\Validation\\AbstractValidator',
        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
        'line' => 14,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
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
        'name' => 'Phalcon\\Validation\\AbstractValidatorComposite',
        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
        'line' => 15,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
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
        'name' => 'Phalcon\\Validation\\Validator\\StringLength\\Max',
        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
        'line' => 16,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Validation\\Validator\\StringLength\\Min',
        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
        'line' => 17,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Validation\\Exception',
        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
        'line' => 18,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
    'line' => 81,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string\'s length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 * Since Phalcon v4.0 this valitor works like a container
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\StringLength as StringLength;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new StringLength(
 *         [
 *             "max"             => 50,
 *             "min"             => 2,
 *             "messageMaximum"  => "We don\'t like really long names",
 *             "messageMinimum"  => "We want more than just their initials",
 *             "includedMaximum" => true,
 *             "includedMinimum" => false,
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new StringLength(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "min" => [
 *                 "name_last"  => 2,
 *                 "name_first" => 4,
 *             ],
 *             "messageMaximum" => [
 *                 "name_last"  => "We don\'t like really long last names",
 *                 "name_first" => "We don\'t like really long first names",
 *             ],
 *             "messageMinimum" => [
 *                 "name_last"  => "We don\'t like too short last names",
 *                 "name_first" => "We don\'t like too short first names",
 *             ],
 *             "includedMaximum" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ],
 *             "includedMinimum" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
    'line' => 82,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'StringLength',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractValidatorComposite',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                'line' => 87,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
              'line' => 87,
              'char' => 52,
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
                  'variable' => 'included',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                    'line' => 89,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                  'line' => 89,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                  'line' => 89,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'message',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                    'line' => 89,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                  'line' => 89,
                  'char' => 49,
                ),
                3 => 
                array (
                  'variable' => 'validator',
                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                  'line' => 89,
                  'char' => 60,
                ),
                4 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                  'line' => 89,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
              'line' => 92,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'options',
                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                'line' => 92,
                'char' => 35,
              ),
              'key' => 'key',
              'value' => 'value',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strcasecmp',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 93,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 93,
                          'char' => 30,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'min',
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 93,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 93,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 93,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 93,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                    'line' => 93,
                    'char' => 43,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'options',
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 95,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'message',
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 95,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 95,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 95,
                        'char' => 43,
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
                              'variable' => 'message',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'options',
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 96,
                                  'char' => 42,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'message',
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 96,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 96,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 96,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 97,
                          'char' => 17,
                        ),
                      ),
                      'elseif_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'isset',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'options',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 97,
                                'char' => 39,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'messageMinimum',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 97,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 97,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 97,
                            'char' => 56,
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
                                  'variable' => 'message',
                                  'expr' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'options',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 98,
                                      'char' => 42,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'messageMinimum',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 98,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 98,
                                    'char' => 58,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 98,
                                  'char' => 58,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 99,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 102,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 102,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'options',
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 102,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'included',
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 102,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 102,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 102,
                        'char' => 44,
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
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'options',
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 103,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'included',
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 103,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 103,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 103,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 104,
                          'char' => 17,
                        ),
                      ),
                      'elseif_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'isset',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'options',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 104,
                                'char' => 39,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'includedMinimum',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 104,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 104,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 104,
                            'char' => 57,
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
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'options',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 105,
                                      'char' => 43,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'includedMinimum',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 105,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 105,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 105,
                                  'char' => 60,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 106,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 108,
                          'char' => 19,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 108,
                      'char' => 19,
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
                          'variable' => 'validator',
                          'expr' => 
                          array (
                            'type' => 'new',
                            'class' => 'Min',
                            'dynamic' => 0,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array',
                                  'left' => 
                                  array (
                                    0 => 
                                    array (
                                      'key' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'min',
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 110,
                                        'char' => 29,
                                      ),
                                      'value' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'value',
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 110,
                                        'char' => 36,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 110,
                                      'char' => 36,
                                    ),
                                    1 => 
                                    array (
                                      'key' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'message',
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 111,
                                        'char' => 33,
                                      ),
                                      'value' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'message',
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 111,
                                        'char' => 42,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 111,
                                      'char' => 42,
                                    ),
                                    2 => 
                                    array (
                                      'key' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'included',
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 112,
                                        'char' => 34,
                                      ),
                                      'value' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'included',
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 113,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 113,
                                      'char' => 21,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 114,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 114,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 114,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 114,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 116,
                      'char' => 21,
                    ),
                    3 => 
                    array (
                      'type' => 'unset',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 116,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'min',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 116,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 116,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 117,
                      'char' => 21,
                    ),
                    4 => 
                    array (
                      'type' => 'unset',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 117,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'message',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 117,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 117,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 118,
                      'char' => 21,
                    ),
                    5 => 
                    array (
                      'type' => 'unset',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 118,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'messageMinimum',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 118,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 118,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 119,
                      'char' => 21,
                    ),
                    6 => 
                    array (
                      'type' => 'unset',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 119,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'included',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 119,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 119,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 120,
                      'char' => 21,
                    ),
                    7 => 
                    array (
                      'type' => 'unset',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 120,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'includedMinimum',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 120,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 120,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 121,
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
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strcasecmp',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'key',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 121,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 121,
                              'char' => 36,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'max',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 121,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 121,
                              'char' => 41,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 121,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 121,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 121,
                        'char' => 49,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'isset',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'options',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 123,
                                'char' => 33,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'message',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 123,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 123,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 123,
                            'char' => 43,
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
                                  'variable' => 'message',
                                  'expr' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'options',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 124,
                                      'char' => 42,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'message',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 124,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 124,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 124,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 125,
                              'char' => 17,
                            ),
                          ),
                          'elseif_statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'isset',
                                'left' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'options',
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 125,
                                    'char' => 39,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'messageMaximum',
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 125,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 125,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 125,
                                'char' => 56,
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
                                      'variable' => 'message',
                                      'expr' => 
                                      array (
                                        'type' => 'array-access',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'options',
                                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                          'line' => 126,
                                          'char' => 42,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'messageMaximum',
                                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                          'line' => 126,
                                          'char' => 57,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 126,
                                        'char' => 58,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 126,
                                      'char' => 58,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 127,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 130,
                              'char' => 18,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 130,
                          'char' => 18,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'isset',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'options',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 130,
                                'char' => 33,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'included',
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 130,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 130,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 130,
                            'char' => 44,
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
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'options',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 131,
                                      'char' => 43,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'included',
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 131,
                                      'char' => 52,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 131,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 131,
                                  'char' => 53,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 132,
                              'char' => 17,
                            ),
                          ),
                          'elseif_statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'isset',
                                'left' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'options',
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 132,
                                    'char' => 39,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'includedMaximum',
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 132,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 132,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 132,
                                'char' => 57,
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
                                        'type' => 'array-access',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'options',
                                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                          'line' => 133,
                                          'char' => 43,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'includedMaximum',
                                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                          'line' => 133,
                                          'char' => 59,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                        'line' => 133,
                                        'char' => 60,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 133,
                                      'char' => 60,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                  'line' => 134,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 136,
                              'char' => 19,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 136,
                          'char' => 19,
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
                              'variable' => 'validator',
                              'expr' => 
                              array (
                                'type' => 'new',
                                'class' => 'Max',
                                'dynamic' => 0,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'array',
                                      'left' => 
                                      array (
                                        0 => 
                                        array (
                                          'key' => 
                                          array (
                                            'type' => 'string',
                                            'value' => 'max',
                                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                            'line' => 138,
                                            'char' => 29,
                                          ),
                                          'value' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'value',
                                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                            'line' => 138,
                                            'char' => 36,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                          'line' => 138,
                                          'char' => 36,
                                        ),
                                        1 => 
                                        array (
                                          'key' => 
                                          array (
                                            'type' => 'string',
                                            'value' => 'message',
                                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                            'line' => 139,
                                            'char' => 33,
                                          ),
                                          'value' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'message',
                                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                            'line' => 139,
                                            'char' => 42,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                          'line' => 139,
                                          'char' => 42,
                                        ),
                                        2 => 
                                        array (
                                          'key' => 
                                          array (
                                            'type' => 'string',
                                            'value' => 'included',
                                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                            'line' => 140,
                                            'char' => 34,
                                          ),
                                          'value' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'included',
                                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                            'line' => 141,
                                            'char' => 21,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                          'line' => 141,
                                          'char' => 21,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                      'line' => 142,
                                      'char' => 17,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                    'line' => 142,
                                    'char' => 17,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                                'line' => 142,
                                'char' => 18,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 142,
                              'char' => 18,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 144,
                          'char' => 21,
                        ),
                        3 => 
                        array (
                          'type' => 'unset',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 144,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'max',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 144,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 144,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 145,
                          'char' => 21,
                        ),
                        4 => 
                        array (
                          'type' => 'unset',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 145,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'message',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 145,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 145,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 146,
                          'char' => 21,
                        ),
                        5 => 
                        array (
                          'type' => 'unset',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 146,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'messageMaximum',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 146,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 146,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 147,
                          'char' => 21,
                        ),
                        6 => 
                        array (
                          'type' => 'unset',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 147,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'included',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 147,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 147,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 148,
                          'char' => 21,
                        ),
                        7 => 
                        array (
                          'type' => 'unset',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 148,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'includedMaximum',
                              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                              'line' => 148,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                            'line' => 148,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                          'line' => 149,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 149,
                      'char' => 18,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 151,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                  'line' => 153,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-append',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'validators',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'validator',
                        'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                        'line' => 153,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 153,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                  'line' => 154,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
              'line' => 156,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                      'line' => 156,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                    'line' => 156,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
                'line' => 156,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
              'line' => 157,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
            'line' => 88,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
          'line' => 87,
          'last-line' => 158,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
      'line' => 82,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/StringLength.zep',
    'line' => 82,
    'char' => 5,
  ),
);