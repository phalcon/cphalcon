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
    'file' => '/app/phalcon/Validation/Validation.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation',
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\Di',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\Di\\Injectable',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 15,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\Filter\\FilterInterface',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 16,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\Messages\\MessageInterface',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\Messages\\Messages',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 18,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\Validation\\ValidationInterface',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 19,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
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
        'name' => 'Phalcon\\Validation\\Exception',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 20,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
    'line' => 21,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Validation\\ValidatorInterface',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 21,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
    'line' => 22,
    'char' => 3,
  ),
  11 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Validation\\CombinedFieldsValidator',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 22,
        'char' => 47,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
    'line' => 28,
    'char' => 2,
  ),
  12 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Validation
 *
 * Allows to validate data using custom or built-in validators
 *',
    'file' => '/app/phalcon/Validation/Validation.zep',
    'line' => 29,
    'char' => 5,
  ),
  13 => 
  array (
    'type' => 'class',
    'name' => 'Validation',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Injectable',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ValidationInterface',
        'file' => '/app/phalcon/Validation/Validation.zep',
        'line' => 30,
        'char' => 1,
      ),
    ),
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
          'name' => 'combinedFieldsValidators',
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 32,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'data',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 32,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 33,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'entity',
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 34,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'filters',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 34,
            'char' => 27,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 35,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'labels',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 35,
            'char' => 26,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 36,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'messages',
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 37,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'validators',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 37,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 38,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'values',
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 42,
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
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'validators',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 43,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 43,
              'char' => 54,
            ),
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
                  'property' => 'validators',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_filter',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validators',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 46,
                          'char' => 23,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 46,
                        'char' => 23,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'closure',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'type' => 'parameter',
                              'name' => 'element',
                              'const' => 0,
                              'data-type' => 'variable',
                              'mandatory' => 0,
                              'reference' => 0,
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 47,
                              'char' => 33,
                            ),
                          ),
                          'right' => 
                          array (
                            0 => 
                            array (
                              'type' => 'return',
                              'expr' => 
                              array (
                                'type' => 'or',
                                'left' => 
                                array (
                                  'type' => 'not-equals',
                                  'left' => 
                                  array (
                                    'type' => 'typeof',
                                    'left' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'element',
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 48,
                                        'char' => 38,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '0',
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 48,
                                        'char' => 40,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 48,
                                      'char' => 43,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 48,
                                    'char' => 43,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'array',
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 48,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 48,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'not',
                                  'left' => 
                                  array (
                                    'type' => 'list',
                                    'left' => 
                                    array (
                                      'type' => 'instanceof',
                                      'left' => 
                                      array (
                                        'type' => 'array-access',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'element',
                                          'file' => '/app/phalcon/Validation/Validation.zep',
                                          'line' => 48,
                                          'char' => 63,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'int',
                                          'value' => '1',
                                          'file' => '/app/phalcon/Validation/Validation.zep',
                                          'line' => 48,
                                          'char' => 65,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 48,
                                        'char' => 76,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'CombinedFieldsValidator',
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 48,
                                        'char' => 101,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 48,
                                      'char' => 101,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 48,
                                    'char' => 102,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 48,
                                  'char' => 102,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 48,
                                'char' => 102,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 49,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 50,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 50,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 50,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 50,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 52,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'combinedFieldsValidators',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_filter',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validators',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 53,
                          'char' => 23,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 53,
                        'char' => 23,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'closure',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'type' => 'parameter',
                              'name' => 'element',
                              'const' => 0,
                              'data-type' => 'variable',
                              'mandatory' => 0,
                              'reference' => 0,
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 54,
                              'char' => 33,
                            ),
                          ),
                          'right' => 
                          array (
                            0 => 
                            array (
                              'type' => 'return',
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
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'element',
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 55,
                                        'char' => 38,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '0',
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 55,
                                        'char' => 40,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 55,
                                      'char' => 43,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 55,
                                    'char' => 43,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'array',
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 55,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 55,
                                  'char' => 52,
                                ),
                                'right' => 
                                array (
                                  'type' => 'instanceof',
                                  'left' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'element',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 55,
                                      'char' => 61,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 55,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 55,
                                    'char' => 74,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'CombinedFieldsValidator',
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 55,
                                    'char' => 99,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 55,
                                  'char' => 99,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 55,
                                'char' => 99,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 56,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 57,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 57,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 57,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 57,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 62,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 62,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 62,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'initialize',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 62,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 62,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 62,
                'char' => 44,
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 63,
                      'char' => 18,
                    ),
                    'name' => 'initialize',
                    'call-type' => 3,
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 63,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 64,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 65,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Validation constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 54,
          'last-line' => 69,
          'char' => 20,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'add',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 70,
              'char' => 34,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ValidatorInterface',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 70,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 70,
              'char' => 66,
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
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 72,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 74,
              'char' => 10,
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
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 74,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 74,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 74,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 74,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'instanceof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validator',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 76,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CombinedFieldsValidator',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 76,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 76,
                    'char' => 61,
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
                          'assign-type' => 'object-property-append',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'combinedFieldsValidators',
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
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 77,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 77,
                                'char' => 62,
                              ),
                              1 => 
                              array (
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'validator',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 77,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 77,
                                'char' => 73,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 77,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 77,
                          'char' => 74,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 78,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 79,
                        'char' => 42,
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
                              'assign-type' => 'object-property-array-index-append',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'validators',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'singleField',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 80,
                                  'char' => 53,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'validator',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 80,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 80,
                              'char' => 68,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 81,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 82,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 83,
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
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 83,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 83,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 83,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 83,
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
                          'assign-type' => 'object-property-array-index-append',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'validators',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 84,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'validator',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 84,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 84,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 85,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 85,
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
                          'value' => 'Field must be passed as array of fields or string',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 88,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 88,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 88,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 89,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 91,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 91,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 92,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a validator to a field
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 71,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 71,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 70,
          'last-line' => 96,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'appendMessage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'MessageInterface',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 97,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 97,
              'char' => 61,
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
                  'variable' => 'messages',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 99,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 101,
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
                  'variable' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 101,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 101,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 101,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 101,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 103,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'messages',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 103,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 103,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 103,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 103,
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
                      'variable' => 'messages',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Messages',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 104,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 104,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 105,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 107,
              'char' => 16,
            ),
            3 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'messages',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 107,
                  'char' => 18,
                ),
                'name' => 'appendMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'message',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 107,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 107,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 107,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 109,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'messages',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 109,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 109,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 111,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 111,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 112,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a message to the messages list
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 98,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 98,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 98,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 97,
          'last-line' => 120,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bind',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'entity',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 121,
              'char' => 32,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 121,
              'char' => 38,
            ),
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 123,
                  'char' => 14,
                ),
                'name' => 'setEntity',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'entity',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 123,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 123,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 123,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 125,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 125,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 125,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 125,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 125,
                      'char' => 44,
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
                          'value' => 'data',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 125,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 125,
                        'char' => 59,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 125,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 125,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 125,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 125,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 125,
                'char' => 69,
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
                          'value' => 'Data to validate must be an array or object',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 126,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 126,
                        'char' => 76,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 126,
                    'char' => 77,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 127,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 129,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 129,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 129,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 131,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 131,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 132,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assigns the data to an entity
     * The entity is used to obtain the validation values
     *
     * @param object entity
     * @param array|object data
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 122,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 121,
          'last-line' => 136,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEntity',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 139,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'entity',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 139,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 139,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 140,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the bound entity
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 138,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 138,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 137,
          'last-line' => 144,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFilters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 145,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 145,
              'char' => 51,
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
                  'variable' => 'filters',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 147,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'fieldFilters',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 147,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 149,
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
                  'variable' => 'filters',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 149,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 149,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 149,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 149,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 151,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'field',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 151,
                  'char' => 19,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 151,
                'char' => 19,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filters',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 152,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 153,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 155,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fieldFilters',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 155,
                    'char' => 48,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 155,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 155,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 155,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 155,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 155,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 156,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 157,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 159,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'fieldFilters',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 159,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 160,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns all the filters or a specific one
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 145,
                'char' => 60,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 146,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 146,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 145,
          'last-line' => 166,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLabel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 167,
              'char' => 39,
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
                  'variable' => 'labels',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 169,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 169,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 171,
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
                  'variable' => 'labels',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 171,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'labels',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 171,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 171,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 171,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 173,
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
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 173,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 173,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 173,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 173,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
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
                          'value' => ', ',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 174,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 174,
                        'char' => 27,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 174,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 174,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 174,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 175,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 177,
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
                  'value' => 'value',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 177,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'labels',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 177,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 177,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 177,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 177,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 178,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 179,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 181,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'field',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 181,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 182,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get label for field
     *
     * @param string field
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
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 168,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 168,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 167,
          'last-line' => 186,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 189,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'messages',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 189,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 189,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 190,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the registered validators
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Messages',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 188,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 188,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 188,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 187,
          'last-line' => 194,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValidators',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 197,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'validators',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 197,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 197,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 198,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the validators added to the validation
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 196,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 196,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 195,
          'last-line' => 202,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 203,
              'char' => 42,
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
                  'variable' => 'entity',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 205,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 205,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 205,
                  'char' => 34,
                ),
                3 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 205,
                  'char' => 40,
                ),
                4 => 
                array (
                  'variable' => 'values',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 205,
                  'char' => 48,
                ),
                5 => 
                array (
                  'variable' => 'filters',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 205,
                  'char' => 57,
                ),
                6 => 
                array (
                  'variable' => 'fieldFilters',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 205,
                  'char' => 71,
                ),
                7 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 206,
                  'char' => 22,
                ),
                8 => 
                array (
                  'variable' => 'filterService',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 206,
                  'char' => 37,
                ),
                9 => 
                array (
                  'variable' => 'camelizedField',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 206,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 208,
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
                  'variable' => 'entity',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 208,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'entity',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 208,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 208,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 208,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 211,
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
                    'value' => 'entity',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 211,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 211,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 211,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 211,
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
                      'variable' => 'camelizedField',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'camelize',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 212,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 212,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 212,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 212,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 213,
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
                      'variable' => 'method',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => 'get',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 213,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'camelizedField',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 213,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 213,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 213,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 215,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'method_exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'entity',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 215,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 215,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 215,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 215,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 215,
                    'char' => 46,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'entity',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 216,
                              'char' => 36,
                            ),
                            'name' => 'method',
                            'call-type' => 2,
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 216,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 216,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 217,
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
                        'type' => 'fcall',
                        'name' => 'method_exists',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'entity',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 217,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 217,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'readAttribute',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 217,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 217,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 217,
                        'char' => 59,
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
                              'variable' => 'value',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'entity',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 218,
                                  'char' => 36,
                                ),
                                'name' => 'readAttribute',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 218,
                                      'char' => 56,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 218,
                                    'char' => 56,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 218,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 218,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 219,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 219,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'property-dynamic-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'entity',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 219,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 219,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 219,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 219,
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
                              'variable' => 'value',
                              'expr' => 
                              array (
                                'type' => 'property-dynamic-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'entity',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 220,
                                  'char' => 36,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 220,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 220,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 220,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 221,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 221,
                      'char' => 18,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 222,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 222,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 223,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 224,
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 225,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 225,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 225,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 225,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 227,
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
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 227,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 227,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 227,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 227,
                          'char' => 48,
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
                              'value' => 'data',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 227,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 227,
                            'char' => 63,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 227,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 227,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 227,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 227,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 227,
                    'char' => 73,
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
                              'value' => 'There is no data to validate',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 228,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 228,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 228,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 229,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 232,
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
                      'variable' => 'values',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 232,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'values',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 232,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 232,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 232,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 234,
                  'char' => 14,
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
                      'value' => 'value',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 234,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'values',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 234,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 234,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 234,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 234,
                    'char' => 43,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 235,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 236,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 238,
                  'char' => 15,
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
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 238,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 238,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 240,
                  'char' => 14,
                ),
                5 => 
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
                        'value' => 'data',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 240,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 240,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 240,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 240,
                    'char' => 37,
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
                            'value' => 'data',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 241,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 241,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 241,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 241,
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
                              'variable' => 'value',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'data',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 242,
                                  'char' => 37,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 242,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 242,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 242,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 243,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 244,
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
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 244,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 244,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 244,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 244,
                        'char' => 44,
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
                              'type' => 'property-dynamic-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'data',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 245,
                                'char' => 31,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 245,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 245,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 245,
                            'char' => 40,
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
                                  'variable' => 'value',
                                  'expr' => 
                                  array (
                                    'type' => 'property-dynamic-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'data',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 246,
                                      'char' => 38,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 246,
                                      'char' => 46,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 246,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 246,
                                  'char' => 46,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 247,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 248,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 249,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 249,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 251,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 251,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 251,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 251,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 252,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 253,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 255,
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
                  'variable' => 'filters',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 255,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 255,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 255,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 255,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 257,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'fieldFilters',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 257,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filters',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 257,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 257,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 257,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 257,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'fieldFilters',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 258,
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
                          'variable' => 'container',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 259,
                              'char' => 38,
                            ),
                            'name' => 'getDI',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 259,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 259,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 261,
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
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 261,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 261,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 261,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 261,
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
                              'variable' => 'container',
                              'expr' => 
                              array (
                                'type' => 'scall',
                                'dynamic-class' => 0,
                                'class' => 'Di',
                                'dynamic' => 0,
                                'name' => 'getDefault',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 262,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 262,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 264,
                          'char' => 22,
                        ),
                        1 => 
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
                                  'value' => 'container',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 264,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 264,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'object',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 264,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 264,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 264,
                            'char' => 60,
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
                                      'type' => 'scall',
                                      'dynamic-class' => 0,
                                      'class' => 'Exception',
                                      'dynamic' => 0,
                                      'name' => 'containerServiceNotFound',
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'string',
                                            'value' => 'the \'filter\' service',
                                            'file' => '/app/phalcon/Validation/Validation.zep',
                                            'line' => 268,
                                            'char' => 29,
                                          ),
                                          'file' => '/app/phalcon/Validation/Validation.zep',
                                          'line' => 268,
                                          'char' => 29,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 269,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 269,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 269,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 270,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 271,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 273,
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
                          'variable' => 'filterService',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'FilterInterface',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 273,
                              'char' => 83,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 273,
                                'char' => 65,
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
                                    'value' => 'filter',
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 273,
                                    'char' => 82,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 273,
                                  'char' => 82,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 273,
                              'char' => 83,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 273,
                            'char' => 83,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 273,
                          'char' => 83,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 275,
                      'char' => 18,
                    ),
                    3 => 
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
                              'value' => 'filterService',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 275,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 275,
                            'char' => 51,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 275,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 275,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 275,
                        'char' => 60,
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
                                  'value' => 'Returned \'filter\' service is invalid',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 276,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 276,
                                'char' => 77,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 276,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 277,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 279,
                      'char' => 19,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filterService',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 279,
                              'char' => 43,
                            ),
                            'name' => 'sanitize',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 279,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 279,
                                'char' => 58,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fieldFilters',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 279,
                                  'char' => 72,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 279,
                                'char' => 72,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 279,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 279,
                          'char' => 73,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 284,
                      'char' => 18,
                    ),
                    5 => 
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
                            'value' => 'entity',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 284,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 284,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 284,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 284,
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
                              'variable' => 'method',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'set',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 285,
                                  'char' => 38,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'camelizedField',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 285,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 285,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 285,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 287,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'method_exists',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'entity',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 287,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 287,
                                'char' => 44,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'method',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 287,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 287,
                                'char' => 52,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 287,
                            'char' => 54,
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
                                  'value' => 'entity',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 288,
                                  'char' => 32,
                                ),
                                'name' => 'method',
                                'call-type' => 2,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 288,
                                      'char' => 47,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 288,
                                    'char' => 47,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 288,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 289,
                              'char' => 21,
                            ),
                          ),
                          'elseif_statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'method_exists',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'entity',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 289,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 289,
                                    'char' => 50,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'writeAttribute',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 289,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 289,
                                    'char' => 66,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 289,
                                'char' => 68,
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
                                      'value' => 'entity',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 290,
                                      'char' => 32,
                                    ),
                                    'name' => 'writeAttribute',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'field',
                                          'file' => '/app/phalcon/Validation/Validation.zep',
                                          'line' => 290,
                                          'char' => 53,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 290,
                                        'char' => 53,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'value',
                                          'file' => '/app/phalcon/Validation/Validation.zep',
                                          'line' => 290,
                                          'char' => 60,
                                        ),
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 290,
                                        'char' => 60,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 290,
                                    'char' => 61,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 291,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 291,
                              'char' => 28,
                            ),
                            1 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'property_exists',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'entity',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 291,
                                      'char' => 52,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 291,
                                    'char' => 52,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'field',
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 291,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 291,
                                    'char' => 59,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 291,
                                'char' => 61,
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
                                      'assign-type' => 'variable-dynamic-object-property',
                                      'operator' => 'assign',
                                      'variable' => 'entity',
                                      'property' => 'field',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'value',
                                        'file' => '/app/phalcon/Validation/Validation.zep',
                                        'line' => 292,
                                        'char' => 52,
                                      ),
                                      'file' => '/app/phalcon/Validation/Validation.zep',
                                      'line' => 292,
                                      'char' => 52,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 293,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 294,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 294,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 296,
                      'char' => 22,
                    ),
                    6 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 296,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 297,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 298,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 301,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'entity',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 301,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 301,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 301,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 301,
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
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'values',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 302,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 302,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 302,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 303,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 305,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 305,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 306,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the a value to validate in the array/object data source
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 203,
                'char' => 51,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 204,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 204,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 203,
          'last-line' => 310,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rule',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 311,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ValidatorInterface',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 311,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 311,
              'char' => 67,
            ),
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 313,
                  'char' => 21,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 313,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 313,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validator',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 313,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 313,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 313,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 314,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Alias of `add` method
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 312,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 312,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 312,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 311,
          'last-line' => 318,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rules',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 319,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validators',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 319,
              'char' => 55,
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
                  'variable' => 'validator',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 321,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 323,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'validators',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 323,
                'char' => 37,
              ),
              'value' => 'validator',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'instanceof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validator',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 324,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ValidatorInterface',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 324,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 324,
                    'char' => 56,
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
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 325,
                          'char' => 22,
                        ),
                        'name' => 'add',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 325,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 325,
                            'char' => 32,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validator',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 325,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 325,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 325,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 326,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 327,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 329,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 329,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 330,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds the validators to a field
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 320,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 320,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 320,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 319,
          'last-line' => 336,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setEntity',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'entity',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 337,
              'char' => 37,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'value' => 'entity',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 339,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 339,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 339,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 339,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 339,
                'char' => 45,
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
                          'value' => 'Entity must be an object',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 340,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 340,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 340,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 341,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 343,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'entity',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'entity',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 343,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 343,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 344,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the bound entity
     *
     * @param object entity
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 338,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 337,
          'last-line' => 351,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFilters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 352,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 352,
              'char' => 50,
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
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 354,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 356,
              'char' => 10,
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
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 356,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 356,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 356,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 356,
                'char' => 34,
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
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 357,
                    'char' => 38,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'filters',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'singleField',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 358,
                              'char' => 46,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filters',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 358,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 358,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 359,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 360,
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
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'field',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 360,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 360,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 360,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 360,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'filters',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 361,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filters',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 361,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 361,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 362,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 362,
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
                          'value' => 'Field must be passed as array of fields or string.',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 365,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 365,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 365,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 366,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 368,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 368,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 369,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds filters to the field
     *
     * @param string field
     * @param array|string filters
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 353,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 353,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 353,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 352,
          'last-line' => 373,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLabels',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'labels',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 374,
              'char' => 44,
            ),
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
                  'property' => 'labels',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'labels',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 376,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 376,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 377,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds labels for fields
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 375,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 374,
          'last-line' => 384,
          'char' => 19,
        ),
        15 => 
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
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 385,
                'char' => 45,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 385,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'entity',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 385,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 385,
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
                  'variable' => 'combinedFieldsValidators',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 387,
                  'char' => 37,
                ),
                1 => 
                array (
                  'variable' => 'field',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 387,
                  'char' => 44,
                ),
                2 => 
                array (
                  'variable' => 'messages',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 387,
                  'char' => 54,
                ),
                3 => 
                array (
                  'variable' => 'scope',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 387,
                  'char' => 61,
                ),
                4 => 
                array (
                  'variable' => 'status',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 387,
                  'char' => 69,
                ),
                5 => 
                array (
                  'variable' => 'validator',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 387,
                  'char' => 80,
                ),
                6 => 
                array (
                  'variable' => 'validatorData',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 388,
                  'char' => 26,
                ),
                7 => 
                array (
                  'variable' => 'validators',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 388,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 390,
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
                  'variable' => 'validatorData',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 390,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validators',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 390,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 390,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 390,
                  'char' => 56,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'combinedFieldsValidators',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 391,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'combinedFieldsValidators',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 391,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 391,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 391,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 393,
              'char' => 10,
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
                      'value' => 'validatorData',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 393,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 393,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 393,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 393,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 393,
                'char' => 51,
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
                          'value' => 'There are no validators to validate',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 394,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 394,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 394,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 395,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 400,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'values',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 400,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 400,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 405,
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
                  'variable' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Messages',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 405,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 405,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 407,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'entity',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 407,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 407,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 407,
                'char' => 28,
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 408,
                      'char' => 18,
                    ),
                    'name' => 'setEntity',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'entity',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 408,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 408,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 408,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 409,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 414,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 414,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 414,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'beforeValidation',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 414,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 414,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 414,
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
                      'variable' => 'status',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 415,
                          'char' => 31,
                        ),
                        'name' => 'beforeValidation',
                        'call-type' => 3,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 415,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 415,
                            'char' => 55,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'entity',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 415,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 415,
                            'char' => 63,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'messages',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 415,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 415,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 415,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 415,
                      'char' => 74,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 417,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'status',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 417,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 417,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 417,
                    'char' => 33,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'status',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 418,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 419,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 420,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 422,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'messages',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 422,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 422,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 424,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'data',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 424,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 424,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 424,
                'char' => 26,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'not-equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 425,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 425,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 425,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 425,
                          'char' => 48,
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
                              'value' => 'data',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 425,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 425,
                            'char' => 63,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 425,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 425,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 425,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 425,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 425,
                    'char' => 73,
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
                              'value' => 'Invalid data to validate',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 426,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 426,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 426,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 427,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 429,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'data',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 429,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 429,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 430,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 432,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'validatorData',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 432,
                'char' => 48,
              ),
              'key' => 'field',
              'value' => 'validators',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'validators',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 433,
                    'char' => 41,
                  ),
                  'value' => 'validator',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
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
                              'value' => 'validator',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 434,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 434,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 434,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 434,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 434,
                        'char' => 56,
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
                                  'value' => 'One of the validators is not valid',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 435,
                                  'char' => 75,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 435,
                                'char' => 75,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 435,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 436,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 442,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 442,
                          'char' => 25,
                        ),
                        'name' => 'preChecking',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 442,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 442,
                            'char' => 43,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validator',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 442,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 442,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 442,
                        'char' => 56,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 444,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 449,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'validator',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 449,
                            'char' => 30,
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
                                'value' => 'this',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 449,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 449,
                              'char' => 44,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 449,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 449,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 449,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 449,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 449,
                        'char' => 63,
                      ),
                      'statements' => 
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
                              'value' => 'validator',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 450,
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
                                  'value' => 'cancelOnFail',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 450,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 450,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 450,
                            'char' => 59,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'break',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 452,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 453,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 454,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 455,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 457,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'combinedFieldsValidators',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 457,
                'char' => 47,
              ),
              'value' => 'scope',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
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
                          'value' => 'scope',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 458,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 458,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 458,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 458,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 458,
                    'char' => 47,
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
                              'value' => 'The validator scope is not valid',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 459,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 459,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 459,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 460,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 462,
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
                      'variable' => 'field',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'scope',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 462,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 462,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 462,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 462,
                      'char' => 37,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'validator',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'scope',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 463,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 463,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 463,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 463,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 465,
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
                          'value' => 'validator',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 465,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 465,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 465,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 465,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 465,
                    'char' => 52,
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
                              'value' => 'One of the validators is not valid',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 466,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 466,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 466,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 467,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 473,
                  'char' => 14,
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
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 473,
                      'char' => 21,
                    ),
                    'name' => 'preChecking',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 473,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 473,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validator',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 473,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 473,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 473,
                    'char' => 52,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 475,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 480,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'validator',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 480,
                        'char' => 26,
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
                            'value' => 'this',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 480,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 480,
                          'char' => 40,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 480,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 480,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 480,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 480,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 480,
                    'char' => 59,
                  ),
                  'statements' => 
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
                          'value' => 'validator',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 481,
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
                              'value' => 'cancelOnFail',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 481,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 481,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 481,
                        'char' => 55,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 483,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 484,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 485,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 490,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 490,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 490,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'afterValidation',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 490,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 490,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 490,
                'char' => 49,
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 491,
                      'char' => 18,
                    ),
                    'name' => 'afterValidation',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 491,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 491,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'entity',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 491,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 491,
                        'char' => 49,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 491,
                            'char' => 56,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'messages',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 491,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 491,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 491,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 491,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 492,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 494,
              'char' => 14,
            ),
            12 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 494,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'messages',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 494,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 494,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 495,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Validate a set of data according to a set of rules
     *
     * @param array|object data
     * @param object entity
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Messages',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 386,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 386,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 386,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 385,
          'last-line' => 499,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'preChecking',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 500,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ValidatorInterface',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 500,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 500,
              'char' => 77,
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
                  'variable' => 'singleField',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 502,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'allowEmpty',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 502,
                  'char' => 36,
                ),
                2 => 
                array (
                  'variable' => 'emptyValue',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 502,
                  'char' => 48,
                ),
                3 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 502,
                  'char' => 55,
                ),
                4 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 502,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 504,
              'char' => 10,
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
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 504,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 504,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 504,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 504,
                'char' => 34,
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
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 505,
                    'char' => 38,
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
                          'variable' => 'result',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 506,
                              'char' => 35,
                            ),
                            'name' => 'preChecking',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'singleField',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 506,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 506,
                                'char' => 59,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'validator',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 506,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 506,
                                'char' => 70,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 506,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 506,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 508,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'result',
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 508,
                        'char' => 27,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'result',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 509,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 510,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 511,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 512,
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
                      'variable' => 'allowEmpty',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validator',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 513,
                          'char' => 40,
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
                              'value' => 'allowEmpty',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 513,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 513,
                            'char' => 61,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'bool',
                              'value' => 'false',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 513,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 513,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 513,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 513,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 515,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'allowEmpty',
                    'file' => '/app/phalcon/Validation/Validation.zep',
                    'line' => 515,
                    'char' => 27,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'method_exists',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'validator',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 516,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 516,
                            'char' => 43,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'isAllowEmpty',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 516,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 516,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 516,
                        'char' => 59,
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
                              'value' => 'validator',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 517,
                              'char' => 38,
                            ),
                            'name' => 'isAllowEmpty',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 517,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 517,
                                'char' => 56,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'field',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 517,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 517,
                                'char' => 63,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 517,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 518,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 520,
                      'char' => 19,
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
                              'value' => 'this',
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 520,
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
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 520,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 520,
                                'char' => 49,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 520,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 520,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 522,
                      'char' => 18,
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
                            'value' => 'allowEmpty',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 522,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 522,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 522,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 522,
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
                            'value' => 'allowEmpty',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 523,
                            'char' => 50,
                          ),
                          'value' => 'emptyValue',
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
                                  'type' => 'variable',
                                  'value' => 'emptyValue',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 524,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 524,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Validation/Validation.zep',
                                'line' => 524,
                                'char' => 49,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'return',
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Validation/Validation.zep',
                                    'line' => 525,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Validation/Validation.zep',
                                  'line' => 526,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Validation/Validation.zep',
                              'line' => 527,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 529,
                          'char' => 26,
                        ),
                        1 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Validation/Validation.zep',
                            'line' => 529,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 530,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 532,
                      'char' => 22,
                    ),
                    3 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Validation/Validation.zep',
                          'line' => 532,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Validation/Validation.zep',
                        'line' => 532,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/Validation.zep',
                      'line' => 533,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validation.zep',
                  'line' => 534,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 536,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 536,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Validation/Validation.zep',
              'line' => 537,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Internal validations, if it returns true, then skip the current validator
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
                'file' => '/app/phalcon/Validation/Validation.zep',
                'line' => 501,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validation.zep',
            'line' => 501,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validation.zep',
          'line' => 500,
          'last-line' => 538,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validation.zep',
      'line' => 29,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validation.zep',
    'line' => 29,
    'char' => 5,
  ),
);