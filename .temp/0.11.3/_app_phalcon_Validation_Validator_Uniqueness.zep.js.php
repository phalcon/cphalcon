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
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
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
        'name' => 'Phalcon\\Validation\\AbstractCombinedFieldsValidator',
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 15,
        'char' => 55,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
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
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 17,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
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
        'name' => 'Phalcon\\Mvc\\CollectionInterface',
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 18,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model',
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 19,
        'char' => 22,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Collection',
        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
        'line' => 20,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
    'line' => 91,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Check that a field is unique in the related table
 *
 * ```php
 * use Phalcon\\Validation\\Validation;
 * use Phalcon\\Validation\\Validator\\Uniqueness as UniquenessValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "model"   => new Users(),
 *             "message" => ":field must be unique",
 *         ]
 *     )
 * );
 * ```
 *
 * Different attribute from the field:
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "model"     => new Users(),
 *             "attribute" => "nick",
 *         ]
 *     )
 * );
 * ```
 *
 * In model:
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator()
 * );
 * ```
 *
 * Combination of fields in model:
 * ```php
 * $validator->add(
 *     [
 *         "firstName",
 *         "lastName",
 *     ],
 *     new UniquenessValidator()
 * );
 * ```
 *
 * It is possible to convert values before validation. This is useful in
 * situations where values need to be converted to do the database lookup:
 *
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "convert" => function (array $values) {
 *                 $values["username"] = strtolower($values["username"]);
 *
 *                 return $values;
 *             }
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
    'line' => 92,
    'char' => 5,
  ),
  11 => 
  array (
    'type' => 'class',
    'name' => 'Uniqueness',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractCombinedFieldsValidator',
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
            'value' => 'Field :field must be unique',
            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
            'line' => 94,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
          'line' => 96,
          'char' => 11,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'columnMap',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
            'line' => 96,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
          'line' => 100,
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
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 101,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 101,
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
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 101,
              'char' => 64,
            ),
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 103,
                    'char' => 18,
                  ),
                  'name' => 'isUniqueness',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'validation',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 103,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 103,
                      'char' => 42,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 103,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 103,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 103,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 103,
                'char' => 51,
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
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 104,
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
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 105,
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
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 105,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 105,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 105,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 105,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 106,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 106,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 106,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 108,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 108,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 109,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 111,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 111,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 112,
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
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 102,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
            'line' => 102,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
          'line' => 101,
          'last-line' => 116,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getColumnNameReal',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 117,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 117,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'globals_get',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'orm.column_renaming',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 120,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 120,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 120,
                  'char' => 46,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 120,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'columnMap',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 120,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 120,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 120,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 120,
                'char' => 65,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'columnMap',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'record',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 121,
                              'char' => 42,
                            ),
                            'name' => 'getDI',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 122,
                            'char' => 18,
                          ),
                          'name' => 'getShared',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'modelsMetadata',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 122,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 122,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 123,
                          'char' => 18,
                        ),
                        'name' => 'getColumnMap',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'record',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 123,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 123,
                            'char' => 38,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 123,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 123,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 124,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 126,
              'char' => 10,
            ),
            1 => 
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 126,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnMap',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 126,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 126,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 126,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 126,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 126,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 126,
                        'char' => 58,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnMap',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 126,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 126,
                      'char' => 68,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 126,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 126,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 126,
                  'char' => 76,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 126,
                'char' => 76,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 127,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'columnMap',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 127,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 127,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 127,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 127,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 128,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 130,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'field',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 130,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 131,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * The column map is used in the case to get real column name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 118,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
            'line' => 118,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
          'line' => 117,
          'last-line' => 133,
          'char' => 22,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'isUniqueness',
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
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 133,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 133,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 133,
              'char' => 71,
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
                  'variable' => 'values',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 135,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'convert',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 135,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'record',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 135,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 135,
                  'char' => 44,
                ),
                4 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 135,
                  'char' => 55,
                ),
                5 => 
                array (
                  'variable' => 'isModel',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 135,
                  'char' => 64,
                ),
                6 => 
                array (
                  'variable' => 'isDocument',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 135,
                  'char' => 76,
                ),
                7 => 
                array (
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 136,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 138,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 138,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 138,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 138,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 138,
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
                      'variable' => 'singleField',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 139,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 139,
                      'char' => 36,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'field',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 140,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 140,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 142,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'field',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'singleField',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 142,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 142,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 143,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 145,
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
                  'variable' => 'values',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 145,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 145,
                  'char' => 24,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'convert',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 146,
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
                          'value' => 'convert',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 146,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 146,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 146,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 146,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 148,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'field',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 148,
                'char' => 34,
              ),
              'value' => 'singleField',
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'values',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'singleField',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 149,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validation',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 149,
                          'char' => 50,
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
                              'value' => 'singleField',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 149,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 149,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 149,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 149,
                      'char' => 72,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 150,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 152,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'convert',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 152,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 152,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 152,
                'char' => 28,
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
                      'variable' => 'values',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'convert',
                        'call-type' => 2,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'values',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 153,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 153,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 153,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 153,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 155,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'is_array',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'values',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 155,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 155,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 155,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 155,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 155,
                    'char' => 43,
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
                              'value' => 'Value conversion must return an array',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 156,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 156,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 156,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 157,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 158,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 160,
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
                  'variable' => 'record',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 160,
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
                          'value' => 'model',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 160,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 160,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 160,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 160,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 162,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'record',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 162,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 162,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'record',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 162,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 162,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 162,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 162,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 162,
                'char' => 52,
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
                      'variable' => 'record',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validation',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 164,
                          'char' => 37,
                        ),
                        'name' => 'getEntity',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 164,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 164,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 166,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'record',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 166,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 166,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 166,
                    'char' => 38,
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
                              'value' => 'Model of record must be set to property \\"model\\"',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 169,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 169,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 169,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 170,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 171,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 173,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'isModel',
                  'expr' => 
                  array (
                    'type' => 'instanceof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'record',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 173,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ModelInterface',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 173,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 173,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 173,
                  'char' => 55,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'isDocument',
                  'expr' => 
                  array (
                    'type' => 'instanceof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'record',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 174,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CollectionInterface',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 174,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 174,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 174,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 176,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'isModel',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 176,
                'char' => 20,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 177,
                          'char' => 31,
                        ),
                        'name' => 'isUniquenessModel',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'record',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 177,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 177,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 177,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 177,
                            'char' => 63,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'values',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 177,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 177,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 177,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 177,
                      'char' => 72,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 178,
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
                    'type' => 'variable',
                    'value' => 'isDocument',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 178,
                    'char' => 29,
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
                          'variable' => 'params',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 179,
                              'char' => 31,
                            ),
                            'name' => 'isUniquenessCollection',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'record',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 179,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 179,
                                'char' => 61,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 179,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 179,
                                'char' => 68,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'values',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 179,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 179,
                                'char' => 76,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 179,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 179,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 180,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 180,
                  'char' => 14,
                ),
              ),
              'else_statements' => 
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
                          'value' => 'The uniqueness validator works only with Phalcon\\\\Mvc\\\\Model or Phalcon\\\\Mvc\\\\Collection',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 183,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 183,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 183,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 184,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 186,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'className',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'get_class',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'record',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 186,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 186,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 186,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 186,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 188,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'scall',
                  'dynamic-class' => 1,
                  'class' => 'className',
                  'dynamic' => 0,
                  'name' => 'count',
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'params',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 188,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 188,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 188,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 188,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 188,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 189,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 134,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
            'line' => 134,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
          'line' => 133,
          'last-line' => 193,
          'char' => 22,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'isUniquenessCollection',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 194,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 194,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 194,
              'char' => 84,
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
                  'variable' => 'exceptConditions',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 196,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'fieldExcept',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 196,
                  'char' => 42,
                ),
                2 => 
                array (
                  'variable' => 'notInValues',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 196,
                  'char' => 55,
                ),
                3 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 196,
                  'char' => 62,
                ),
                4 => 
                array (
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 196,
                  'char' => 75,
                ),
                5 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 197,
                  'char' => 19,
                ),
                6 => 
                array (
                  'variable' => 'except',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 197,
                  'char' => 27,
                ),
                7 => 
                array (
                  'variable' => 'singleExcept',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 197,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 199,
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
                  'variable' => 'exceptConditions',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 199,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 199,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 200,
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
                  'variable' => 'params',
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
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 201,
                          'char' => 24,
                        ),
                        'value' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 202,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 202,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 202,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 202,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 204,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'field',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 204,
                'char' => 34,
              ),
              'value' => 'singleField',
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
                      'operator' => 'assign',
                      'variable' => 'fieldExcept',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 205,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 205,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 206,
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
                      'variable' => 'notInValues',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 206,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 206,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 207,
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
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'values',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 207,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'singleField',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 207,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 207,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 207,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 209,
                  'char' => 15,
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
                      'variable' => 'except',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 209,
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
                              'value' => 'except',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 209,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 209,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 209,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 209,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 211,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 211,
                          'char' => 34,
                        ),
                        1 => 
                        array (
                          'type' => 'variable',
                          'value' => 'singleField',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 211,
                          'char' => 47,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 211,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 211,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 213,
                  'char' => 14,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'except',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 213,
                    'char' => 23,
                  ),
                  'statements' => 
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
                              'value' => 'except',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 214,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 214,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 214,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 214,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'greater',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'count',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 214,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 214,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 214,
                            'char' => 59,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 214,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 214,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 214,
                        'char' => 63,
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
                                'value' => 'except',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 215,
                                'char' => 36,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'singleField',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 215,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 215,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 215,
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
                                  'variable' => 'fieldExcept',
                                  'expr' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'except',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 216,
                                      'char' => 49,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'singleField',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 216,
                                      'char' => 61,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 216,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 216,
                                  'char' => 62,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 217,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 218,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 220,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fieldExcept',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 220,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 220,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 220,
                        'char' => 40,
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
                                'value' => 'fieldExcept',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 221,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 221,
                              'char' => 44,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 221,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 221,
                            'char' => 52,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'for',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'fieldExcept',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 222,
                                'char' => 57,
                              ),
                              'value' => 'singleExcept',
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
                                      'assign-type' => 'variable-append',
                                      'operator' => 'assign',
                                      'variable' => 'notInValues',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'singleExcept',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 223,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 223,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 224,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 226,
                              'char' => 27,
                            ),
                            1 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'exceptConditions',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'singleField',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 226,
                                      'char' => 57,
                                    ),
                                  ),
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
                                          'value' => '$nin',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 227,
                                          'char' => 33,
                                        ),
                                        'value' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'notInValues',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 228,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 228,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 228,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 228,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 229,
                              'char' => 21,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'exceptConditions',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'singleField',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 230,
                                      'char' => 57,
                                    ),
                                  ),
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
                                          'value' => '$ne',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 231,
                                          'char' => 32,
                                        ),
                                        'value' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'fieldExcept',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 232,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 232,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 232,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 232,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 233,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 234,
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
                                  'value' => 'except',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 234,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 234,
                                'char' => 41,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'array',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 234,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 234,
                              'char' => 50,
                            ),
                            'right' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'count',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 234,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 234,
                                    'char' => 63,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 234,
                                'char' => 66,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 234,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 234,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 234,
                            'char' => 70,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'for',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'except',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 235,
                                'char' => 48,
                              ),
                              'value' => 'singleExcept',
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
                                      'assign-type' => 'variable-append',
                                      'operator' => 'assign',
                                      'variable' => 'notInValues',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'singleExcept',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 236,
                                        'char' => 57,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 236,
                                      'char' => 57,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 237,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 239,
                              'char' => 23,
                            ),
                            1 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'params',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'conditions',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 239,
                                      'char' => 42,
                                    ),
                                    1 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'singleField',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 239,
                                      'char' => 55,
                                    ),
                                  ),
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
                                          'value' => '$nin',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 240,
                                          'char' => 29,
                                        ),
                                        'value' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'notInValues',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 241,
                                          'char' => 21,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 241,
                                        'char' => 21,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 241,
                                    'char' => 22,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 241,
                                  'char' => 22,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 242,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 242,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'count',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'field',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 242,
                                    'char' => 37,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 242,
                                  'char' => 37,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 242,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 242,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 242,
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
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'params',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'conditions',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 243,
                                      'char' => 42,
                                    ),
                                    1 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'singleField',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 243,
                                      'char' => 55,
                                    ),
                                  ),
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
                                          'value' => '$ne',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 244,
                                          'char' => 28,
                                        ),
                                        'value' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'except',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 245,
                                          'char' => 21,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 245,
                                        'char' => 21,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 245,
                                    'char' => 22,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 245,
                                  'char' => 22,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 246,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 247,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 247,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 248,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 250,
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'record',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 250,
                    'char' => 19,
                  ),
                  'name' => 'getDirtyState',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 250,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'Collection',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 250,
                    'char' => 74,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'DIRTY_STATE_PERSISTENT',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 250,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 250,
                  'char' => 74,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 250,
                'char' => 74,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 251,
                          'char' => 34,
                        ),
                        1 => 
                        array (
                          'type' => 'string',
                          'value' => '_id',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 251,
                          'char' => 39,
                        ),
                      ),
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
                              'value' => '$ne',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 252,
                              'char' => 20,
                            ),
                            'value' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'record',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 252,
                                'char' => 29,
                              ),
                              'name' => 'getId',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 253,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 253,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 253,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 253,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 254,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 256,
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
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'exceptConditions',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 256,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 256,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 256,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 257,
                          'char' => 34,
                        ),
                        1 => 
                        array (
                          'type' => 'string',
                          'value' => '$or',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 257,
                          'char' => 39,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'array',
                        'left' => 
                        array (
                          0 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'exceptConditions',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 257,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 257,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 257,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 257,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 258,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 260,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'params',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 260,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 261,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Uniqueness method used for collection
     *',
          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
          'line' => 194,
          'last-line' => 265,
          'char' => 22,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'isUniquenessModel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 266,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 266,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 266,
              'char' => 79,
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
                  'variable' => 'index',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 268,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 268,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'attribute',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 268,
                  'char' => 37,
                ),
                3 => 
                array (
                  'variable' => 'metaData',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 268,
                  'char' => 47,
                ),
                4 => 
                array (
                  'variable' => 'primaryField',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 268,
                  'char' => 61,
                ),
                5 => 
                array (
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 268,
                  'char' => 74,
                ),
                6 => 
                array (
                  'variable' => 'fieldExcept',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 269,
                  'char' => 24,
                ),
                7 => 
                array (
                  'variable' => 'singleExcept',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 269,
                  'char' => 38,
                ),
                8 => 
                array (
                  'variable' => 'notInValues',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 269,
                  'char' => 51,
                ),
                9 => 
                array (
                  'variable' => 'exceptConditions',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 269,
                  'char' => 69,
                ),
                10 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 269,
                  'char' => 76,
                ),
                11 => 
                array (
                  'variable' => 'except',
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 270,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 272,
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
                  'variable' => 'exceptConditions',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 272,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 272,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'index',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 273,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 273,
                  'char' => 23,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'params',
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
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 275,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 275,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 275,
                        'char' => 31,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'bind',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 276,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 277,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 277,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 277,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 277,
                  'char' => 14,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'except',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 278,
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
                          'value' => 'except',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 278,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 278,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 278,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 278,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 280,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'field',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 280,
                'char' => 34,
              ),
              'value' => 'singleField',
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
                      'operator' => 'assign',
                      'variable' => 'fieldExcept',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 281,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 281,
                      'char' => 35,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'notInValues',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 282,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 282,
                      'char' => 33,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'values',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 283,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'singleField',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 283,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 283,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 283,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 285,
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
                      'variable' => 'attribute',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 285,
                          'char' => 34,
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
                              'value' => 'attribute',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 285,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 285,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'singleField',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 285,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 285,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 285,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 285,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 286,
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
                      'variable' => 'attribute',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 286,
                          'char' => 34,
                        ),
                        'name' => 'getColumnNameReal',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'record',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 286,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 286,
                            'char' => 59,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'attribute',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 286,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 286,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 286,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 286,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 288,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 288,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 288,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 288,
                    'char' => 30,
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
                          'assign-type' => 'array-index-append',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'conditions',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 289,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'attribute',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 289,
                                'char' => 54,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' = ?',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 289,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 289,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 289,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 289,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 289,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 290,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index-append',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'bind',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 290,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 290,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 290,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 291,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'incr',
                          'variable' => 'index',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 291,
                          'char' => 28,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 292,
                      'char' => 13,
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
                          'assign-type' => 'array-index-append',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'conditions',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 293,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'attribute',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 293,
                              'char' => 54,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ' IS NULL',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 293,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 293,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 293,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 294,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 296,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'except',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 296,
                    'char' => 23,
                  ),
                  'statements' => 
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
                              'value' => 'except',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 297,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 297,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 297,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 297,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'not-identical',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'array_keys',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'except',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 297,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 297,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 297,
                            'char' => 67,
                          ),
                          'right' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'range',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 297,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 297,
                                'char' => 76,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'sub',
                                  'left' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'count',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'except',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 297,
                                          'char' => 90,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 297,
                                        'char' => 90,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 297,
                                    'char' => 92,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 297,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 297,
                                  'char' => 95,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 297,
                                'char' => 95,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 297,
                            'char' => 97,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 297,
                          'char' => 97,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 297,
                        'char' => 97,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'except',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 298,
                            'char' => 60,
                          ),
                          'key' => 'singleField',
                          'value' => 'fieldExcept',
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
                                  'operator' => 'assign',
                                  'variable' => 'attribute',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 299,
                                      'char' => 46,
                                    ),
                                    'name' => 'getColumnNameReal',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'record',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 300,
                                          'char' => 35,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 300,
                                        'char' => 35,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 301,
                                            'char' => 34,
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
                                                'value' => 'attribute',
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 301,
                                                'char' => 54,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 301,
                                              'char' => 54,
                                            ),
                                            1 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'singleField',
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 301,
                                                'char' => 67,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 301,
                                              'char' => 67,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 302,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 302,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 302,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 302,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 304,
                              'char' => 26,
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
                                    'value' => 'fieldExcept',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 304,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 304,
                                  'char' => 48,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'array',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 304,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 304,
                                'char' => 56,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'for',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'fieldExcept',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 305,
                                    'char' => 61,
                                  ),
                                  'value' => 'singleExcept',
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
                                          'assign-type' => 'variable-append',
                                          'operator' => 'assign',
                                          'variable' => 'notInValues',
                                          'expr' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '?',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 306,
                                              'char' => 55,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'index',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 306,
                                              'char' => 62,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 306,
                                            'char' => 62,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 306,
                                          'char' => 62,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 307,
                                      'char' => 35,
                                    ),
                                    1 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'array-index-append',
                                          'operator' => 'assign',
                                          'variable' => 'params',
                                          'index-expr' => 
                                          array (
                                            0 => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'bind',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 307,
                                              'char' => 48,
                                            ),
                                          ),
                                          'expr' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'singleExcept',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 307,
                                            'char' => 66,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 307,
                                          'char' => 66,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 308,
                                      'char' => 35,
                                    ),
                                    2 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'incr',
                                          'variable' => 'index',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 308,
                                          'char' => 44,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 309,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 311,
                                  'char' => 31,
                                ),
                                1 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'variable-append',
                                      'operator' => 'assign',
                                      'variable' => 'exceptConditions',
                                      'expr' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'attribute',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 311,
                                              'char' => 64,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ' NOT IN (',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 311,
                                              'char' => 76,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 311,
                                            'char' => 76,
                                          ),
                                          'right' => 
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
                                                  'value' => ',',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 311,
                                                  'char' => 84,
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 311,
                                                'char' => 84,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'notInValues',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 311,
                                                  'char' => 97,
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 311,
                                                'char' => 97,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 311,
                                            'char' => 99,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 311,
                                          'char' => 99,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ')',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 311,
                                          'char' => 102,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 311,
                                        'char' => 102,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 311,
                                      'char' => 102,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 312,
                                  'char' => 25,
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
                                      'assign-type' => 'variable-append',
                                      'operator' => 'assign',
                                      'variable' => 'exceptConditions',
                                      'expr' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'attribute',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 313,
                                            'char' => 64,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => ' <> ?',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 313,
                                            'char' => 72,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 313,
                                          'char' => 72,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'index',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 313,
                                          'char' => 79,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 313,
                                        'char' => 79,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 313,
                                      'char' => 79,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 314,
                                  'char' => 31,
                                ),
                                1 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'array-index-append',
                                      'operator' => 'assign',
                                      'variable' => 'params',
                                      'index-expr' => 
                                      array (
                                        0 => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'bind',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 314,
                                          'char' => 44,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'fieldExcept',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 314,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 314,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 315,
                                  'char' => 31,
                                ),
                                2 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'incr',
                                      'variable' => 'index',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 315,
                                      'char' => 40,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 316,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 317,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 318,
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
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'count',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'field',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 318,
                                    'char' => 37,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 318,
                                  'char' => 37,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 318,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 318,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 318,
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
                                  'variable' => 'attribute',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 319,
                                      'char' => 42,
                                    ),
                                    'name' => 'getColumnNameReal',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'record',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 320,
                                          'char' => 31,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 320,
                                        'char' => 31,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 321,
                                            'char' => 30,
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
                                                'value' => 'attribute',
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 321,
                                                'char' => 50,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 321,
                                              'char' => 50,
                                            ),
                                            1 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'array-access',
                                                'left' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'field',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 321,
                                                  'char' => 57,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '0',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 321,
                                                  'char' => 59,
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 321,
                                                'char' => 60,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 321,
                                              'char' => 60,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 322,
                                          'char' => 21,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 322,
                                        'char' => 21,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 322,
                                    'char' => 22,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 322,
                                  'char' => 22,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 324,
                              'char' => 22,
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
                                    'value' => 'except',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 324,
                                    'char' => 39,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 324,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'array',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 324,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 324,
                                'char' => 47,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'for',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'except',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 325,
                                    'char' => 52,
                                  ),
                                  'value' => 'singleExcept',
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
                                          'assign-type' => 'variable-append',
                                          'operator' => 'assign',
                                          'variable' => 'notInValues',
                                          'expr' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '?',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 326,
                                              'char' => 51,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'index',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 326,
                                              'char' => 58,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 326,
                                            'char' => 58,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 326,
                                          'char' => 58,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 327,
                                      'char' => 31,
                                    ),
                                    1 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'array-index-append',
                                          'operator' => 'assign',
                                          'variable' => 'params',
                                          'index-expr' => 
                                          array (
                                            0 => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'bind',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 327,
                                              'char' => 44,
                                            ),
                                          ),
                                          'expr' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'singleExcept',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 327,
                                            'char' => 62,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 327,
                                          'char' => 62,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 328,
                                      'char' => 31,
                                    ),
                                    2 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'incr',
                                          'variable' => 'index',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 328,
                                          'char' => 40,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 329,
                                      'char' => 25,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 331,
                                  'char' => 27,
                                ),
                                1 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'variable-append',
                                      'operator' => 'assign',
                                      'variable' => 'exceptConditions',
                                      'expr' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'attribute',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 331,
                                              'char' => 60,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ' NOT IN (',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 331,
                                              'char' => 72,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 331,
                                            'char' => 72,
                                          ),
                                          'right' => 
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
                                                  'value' => ',',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 331,
                                                  'char' => 80,
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 331,
                                                'char' => 80,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'notInValues',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 331,
                                                  'char' => 93,
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 331,
                                                'char' => 93,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 331,
                                            'char' => 95,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 331,
                                          'char' => 95,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ')',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 331,
                                          'char' => 98,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 331,
                                        'char' => 98,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 331,
                                      'char' => 98,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 332,
                                  'char' => 21,
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
                                      'assign-type' => 'array-index-append',
                                      'operator' => 'assign',
                                      'variable' => 'params',
                                      'index-expr' => 
                                      array (
                                        0 => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'conditions',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 333,
                                          'char' => 46,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'attribute',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 333,
                                            'char' => 62,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'string',
                                            'value' => ' <> ?',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 333,
                                            'char' => 70,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 333,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'index',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 333,
                                          'char' => 77,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 333,
                                        'char' => 77,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 333,
                                      'char' => 77,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 334,
                                  'char' => 27,
                                ),
                                1 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'array-index-append',
                                      'operator' => 'assign',
                                      'variable' => 'params',
                                      'index-expr' => 
                                      array (
                                        0 => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'bind',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 334,
                                          'char' => 40,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'except',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 334,
                                        'char' => 52,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 334,
                                      'char' => 52,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 335,
                                  'char' => 27,
                                ),
                                2 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'incr',
                                      'variable' => 'index',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 335,
                                      'char' => 36,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 336,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 337,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 337,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'greater',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'count',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'field',
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 337,
                                    'char' => 37,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 337,
                                  'char' => 37,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 337,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 337,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 337,
                            'char' => 43,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'for',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 338,
                                'char' => 46,
                              ),
                              'value' => 'singleField',
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
                                      'operator' => 'assign',
                                      'variable' => 'attribute',
                                      'expr' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 339,
                                          'char' => 46,
                                        ),
                                        'name' => 'getColumnNameReal',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'record',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 340,
                                              'char' => 35,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 340,
                                            'char' => 35,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'mcall',
                                              'variable' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'this',
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 341,
                                                'char' => 34,
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
                                                    'value' => 'attribute',
                                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                    'line' => 341,
                                                    'char' => 54,
                                                  ),
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 341,
                                                  'char' => 54,
                                                ),
                                                1 => 
                                                array (
                                                  'parameter' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'singleField',
                                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                    'line' => 341,
                                                    'char' => 67,
                                                  ),
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 341,
                                                  'char' => 67,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 342,
                                              'char' => 25,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 342,
                                            'char' => 25,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 342,
                                        'char' => 26,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 342,
                                      'char' => 26,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 344,
                                  'char' => 26,
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
                                        'value' => 'except',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 344,
                                        'char' => 43,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 344,
                                      'char' => 43,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'array',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 344,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 344,
                                    'char' => 51,
                                  ),
                                  'statements' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'for',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'except',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 345,
                                        'char' => 56,
                                      ),
                                      'value' => 'singleExcept',
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
                                              'assign-type' => 'variable-append',
                                              'operator' => 'assign',
                                              'variable' => 'notInValues',
                                              'expr' => 
                                              array (
                                                'type' => 'concat',
                                                'left' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => '?',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 346,
                                                  'char' => 55,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'index',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 346,
                                                  'char' => 62,
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 346,
                                                'char' => 62,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 346,
                                              'char' => 62,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 347,
                                          'char' => 35,
                                        ),
                                        1 => 
                                        array (
                                          'type' => 'let',
                                          'assignments' => 
                                          array (
                                            0 => 
                                            array (
                                              'assign-type' => 'array-index-append',
                                              'operator' => 'assign',
                                              'variable' => 'params',
                                              'index-expr' => 
                                              array (
                                                0 => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => 'bind',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 347,
                                                  'char' => 48,
                                                ),
                                              ),
                                              'expr' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'singleExcept',
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 347,
                                                'char' => 66,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 347,
                                              'char' => 66,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 348,
                                          'char' => 35,
                                        ),
                                        2 => 
                                        array (
                                          'type' => 'let',
                                          'assignments' => 
                                          array (
                                            0 => 
                                            array (
                                              'assign-type' => 'incr',
                                              'variable' => 'index',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 348,
                                              'char' => 44,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 349,
                                          'char' => 29,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 351,
                                      'char' => 31,
                                    ),
                                    1 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'variable-append',
                                          'operator' => 'assign',
                                          'variable' => 'exceptConditions',
                                          'expr' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'concat',
                                              'left' => 
                                              array (
                                                'type' => 'concat',
                                                'left' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'attribute',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 351,
                                                  'char' => 64,
                                                ),
                                                'right' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ' NOT IN (',
                                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                  'line' => 351,
                                                  'char' => 76,
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 351,
                                                'char' => 76,
                                              ),
                                              'right' => 
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
                                                      'value' => ',',
                                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                      'line' => 351,
                                                      'char' => 84,
                                                    ),
                                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                    'line' => 351,
                                                    'char' => 84,
                                                  ),
                                                  1 => 
                                                  array (
                                                    'parameter' => 
                                                    array (
                                                      'type' => 'variable',
                                                      'value' => 'notInValues',
                                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                      'line' => 351,
                                                      'char' => 97,
                                                    ),
                                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                    'line' => 351,
                                                    'char' => 97,
                                                  ),
                                                ),
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 351,
                                                'char' => 99,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 351,
                                              'char' => 99,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ')',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 351,
                                              'char' => 102,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 351,
                                            'char' => 102,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 351,
                                          'char' => 102,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 352,
                                      'char' => 25,
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
                                          'assign-type' => 'array-index-append',
                                          'operator' => 'assign',
                                          'variable' => 'params',
                                          'index-expr' => 
                                          array (
                                            0 => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'conditions',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 353,
                                              'char' => 50,
                                            ),
                                          ),
                                          'expr' => 
                                          array (
                                            'type' => 'concat',
                                            'left' => 
                                            array (
                                              'type' => 'concat',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'attribute',
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 353,
                                                'char' => 66,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => ' <> ?',
                                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                                'line' => 353,
                                                'char' => 74,
                                              ),
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 353,
                                              'char' => 74,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'index',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 353,
                                              'char' => 81,
                                            ),
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 353,
                                            'char' => 81,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 353,
                                          'char' => 81,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 354,
                                      'char' => 31,
                                    ),
                                    1 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'array-index-append',
                                          'operator' => 'assign',
                                          'variable' => 'params',
                                          'index-expr' => 
                                          array (
                                            0 => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'bind',
                                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                              'line' => 354,
                                              'char' => 44,
                                            ),
                                          ),
                                          'expr' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'except',
                                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                            'line' => 354,
                                            'char' => 56,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 354,
                                          'char' => 56,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 355,
                                      'char' => 31,
                                    ),
                                    2 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'incr',
                                          'variable' => 'index',
                                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                          'line' => 355,
                                          'char' => 40,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 356,
                                      'char' => 25,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 357,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 358,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 359,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 359,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 360,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 365,
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'record',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 365,
                    'char' => 19,
                  ),
                  'name' => 'getDirtyState',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 365,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'Model',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 365,
                    'char' => 69,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'DIRTY_STATE_PERSISTENT',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 365,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 365,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 365,
                'char' => 69,
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
                      'variable' => 'metaData',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'record',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 366,
                            'char' => 35,
                          ),
                          'name' => 'getDI',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 366,
                          'char' => 44,
                        ),
                        'name' => 'getShared',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'modelsMetadata',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 366,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 366,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 366,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 366,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 368,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'metaData',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 368,
                      'char' => 42,
                    ),
                    'name' => 'getPrimaryKeyAttributes',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'record',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 368,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 368,
                        'char' => 73,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 368,
                    'char' => 75,
                  ),
                  'value' => 'primaryField',
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
                          'assign-type' => 'array-index-append',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'conditions',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 369,
                              'char' => 38,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 369,
                                  'char' => 49,
                                ),
                                'name' => 'getColumnNameReal',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'record',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 369,
                                      'char' => 74,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 369,
                                    'char' => 74,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'primaryField',
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 369,
                                      'char' => 88,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 369,
                                    'char' => 88,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 369,
                                'char' => 90,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ' <> ?',
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 369,
                                'char' => 98,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 369,
                              'char' => 98,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 369,
                              'char' => 105,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 369,
                            'char' => 105,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 369,
                          'char' => 105,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 371,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index-append',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'bind',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 371,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'record',
                              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                              'line' => 371,
                              'char' => 45,
                            ),
                            'name' => 'readAttribute',
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
                                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                    'line' => 372,
                                    'char' => 26,
                                  ),
                                  'name' => 'getColumnNameReal',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'record',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 372,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 372,
                                      'char' => 51,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'primaryField',
                                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                        'line' => 372,
                                        'char' => 65,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                      'line' => 372,
                                      'char' => 65,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 373,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 373,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 373,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 373,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 375,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'incr',
                          'variable' => 'index',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 375,
                          'char' => 28,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 376,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 377,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 379,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'exceptConditions',
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 379,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 379,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 379,
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
                      'assign-type' => 'array-index-append',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'conditions',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 380,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '(',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 380,
                            'char' => 42,
                          ),
                          'right' => 
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
                                  'value' => ' OR ',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 380,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 380,
                                'char' => 53,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'exceptConditions',
                                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                  'line' => 380,
                                  'char' => 71,
                                ),
                                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                                'line' => 380,
                                'char' => 71,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 380,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 380,
                          'char' => 73,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 380,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 380,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 380,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 381,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 383,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'params',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'conditions',
                      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                      'line' => 383,
                      'char' => 30,
                    ),
                  ),
                  'expr' => 
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
                          'value' => ' AND ',
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 384,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 384,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 385,
                            'char' => 19,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'conditions',
                            'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                            'line' => 385,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                          'line' => 386,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                        'line' => 386,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                    'line' => 386,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                  'line' => 386,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 388,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'params',
                'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
                'line' => 388,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
              'line' => 389,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Uniqueness method used for model
     *',
          'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
          'line' => 266,
          'last-line' => 390,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
      'line' => 92,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Uniqueness.zep',
    'line' => 92,
    'char' => 5,
  ),
);