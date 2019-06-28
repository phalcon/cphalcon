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
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
        'line' => 15,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
    'line' => 56,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Check if a value is included into a list of values
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\InclusionIn;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "status",
 *     new InclusionIn(
 *         [
 *             "message" => "The status must be A or B",
 *             "domain"  => ["A", "B"],
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "status",
 *         "type",
 *     ],
 *     new InclusionIn(
 *         [
 *             "message" => [
 *                 "status" => "The status must be A or B",
 *                 "type"   => "The status must be 1 or 2",
 *             ],
 *             "domain" => [
 *                 "status" => ["A", "B"],
 *                 "type"   => [1, 2],
 *             ]
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
    'line' => 57,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'InclusionIn',
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
            'value' => 'Field :field must be a part of list: :domain',
            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
            'line' => 59,
            'char' => 70,
          ),
          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                'line' => 64,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 66,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'domain',
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 66,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'replacePairs',
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 66,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'strict',
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 66,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'fieldDomain',
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 66,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
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
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 68,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 68,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 68,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 68,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 73,
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
                  'variable' => 'domain',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 73,
                      'char' => 27,
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
                          'value' => 'domain',
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 73,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 73,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 73,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 73,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 75,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'fieldDomain',
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 75,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'domain',
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 75,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 75,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 75,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                'line' => 75,
                'char' => 45,
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
                        'value' => 'fieldDomain',
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 76,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 76,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 76,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 76,
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
                          'variable' => 'domain',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'fieldDomain',
                            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                            'line' => 77,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 77,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 78,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 79,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 81,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'domain',
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 81,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 81,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 81,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 81,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                'line' => 81,
                'char' => 44,
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
                          'value' => 'Option \'domain\' must be an array',
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 82,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 82,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 82,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 83,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 85,
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
                  'variable' => 'strict',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 85,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 85,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 87,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 87,
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
                      'value' => 'strict',
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 87,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 87,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                'line' => 87,
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
                      'variable' => 'strict',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 88,
                          'char' => 31,
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
                              'value' => 'strict',
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 88,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                            'line' => 88,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 88,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 88,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 90,
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
                        'value' => 'strict',
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 90,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 90,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 90,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 90,
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
                          'variable' => 'strict',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'strict',
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 91,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 91,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                            'line' => 91,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 91,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 92,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 94,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'strict',
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 94,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 94,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'boolean',
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 94,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 94,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 94,
                    'char' => 50,
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
                              'value' => 'Option \'strict\' must be a bool',
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 95,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                            'line' => 95,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 95,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 96,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 97,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 102,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'in_array',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 102,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 102,
                      'char' => 27,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'domain',
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 102,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 102,
                      'char' => 35,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'strict',
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 102,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 102,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 102,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                'line' => 102,
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
                              'value' => ':domain',
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 104,
                              'char' => 24,
                            ),
                            'value' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'join',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ', ',
                                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                                    'line' => 104,
                                    'char' => 33,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                                  'line' => 104,
                                  'char' => 33,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'domain',
                                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                                    'line' => 104,
                                    'char' => 41,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                                  'line' => 104,
                                  'char' => 41,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 105,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                            'line' => 105,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 105,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 105,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 107,
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
                      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                      'line' => 107,
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
                            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                            'line' => 108,
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
                                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                                'line' => 108,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 108,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                                'line' => 108,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 108,
                              'char' => 55,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'replacePairs',
                                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                                'line' => 108,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                              'line' => 108,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                          'line' => 109,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                        'line' => 109,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 109,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 111,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                    'line' => 111,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                  'line' => 112,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 114,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                'line' => 114,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
              'line' => 115,
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
                'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
                'line' => 65,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
            'line' => 65,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
          'line' => 64,
          'last-line' => 116,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
      'line' => 57,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/InclusionIn.zep',
    'line' => 57,
    'char' => 5,
  ),
);