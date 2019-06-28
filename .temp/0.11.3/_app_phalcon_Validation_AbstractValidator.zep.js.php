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
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation',
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
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
        'name' => 'Phalcon\\Collection',
        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
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
        'name' => 'Phalcon\\Messages\\Message',
        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
        'line' => 15,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
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
        'name' => 'Phalcon\\Validation\\Validation',
        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
        'line' => 16,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
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
        'name' => 'Phalcon\\Validation\\Exception',
        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
        'line' => 17,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
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
        'name' => 'Phalcon\\Validation\\ValidatorInterface',
        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
        'line' => 18,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
    'line' => 22,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This is a base class for validators
 *',
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
    'line' => 23,
    'char' => 8,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'AbstractValidator',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ValidatorInterface',
        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
        'line' => 24,
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
          'name' => 'template',
          'docblock' => '**
    * Message template
    *
    * @var string|null
    *',
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 36,
          'char' => 5,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'templates',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 37,
            'char' => 29,
          ),
          'docblock' => '**
    * Message templates
    *
    * @var array
    *',
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 39,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 43,
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
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 44,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 44,
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
                  'variable' => 'template',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 46,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 48,
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
                  'variable' => 'template',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'current',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'Arr',
                          'dynamic' => 0,
                          'name' => 'whiteList',
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'options',
                                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                'line' => 48,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 48,
                              'char' => 54,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'array',
                                'left' => 
                                array (
                                  0 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'template',
                                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                      'line' => 48,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                    'line' => 48,
                                    'char' => 65,
                                  ),
                                  1 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'message',
                                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                      'line' => 48,
                                      'char' => 74,
                                    ),
                                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                    'line' => 48,
                                    'char' => 74,
                                  ),
                                  2 => 
                                  array (
                                    'value' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '0',
                                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                      'line' => 48,
                                      'char' => 77,
                                    ),
                                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                    'line' => 48,
                                    'char' => 77,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                'line' => 48,
                                'char' => 78,
                              ),
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 48,
                              'char' => 78,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 48,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 48,
                        'char' => 79,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 48,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 48,
                  'char' => 80,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 50,
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
                    'value' => 'template',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 50,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 50,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 50,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 50,
                'char' => 37,
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
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 51,
                      'char' => 18,
                    ),
                    'name' => 'setTemplates',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'template',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 51,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 51,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 51,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 52,
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
                        'value' => 'template',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 52,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 52,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 52,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 52,
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
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 53,
                          'char' => 18,
                        ),
                        'name' => 'setTemplate',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'template',
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 53,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 53,
                            'char' => 39,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 53,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 54,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 56,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 56,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'template',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 56,
                'char' => 21,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 57,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'template',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 57,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 57,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 58,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 58,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'message',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 58,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 58,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 59,
                  'char' => 17,
                ),
                2 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 59,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 59,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 59,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 60,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 62,
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
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 62,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 62,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 63,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Validation\\Validator constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 45,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 44,
          'last-line' => 70,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTemplate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 71,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 71,
              'char' => 53,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'field',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 74,
                    'char' => 20,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 74,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 74,
                  'char' => 28,
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
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 74,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'templates',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 74,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 74,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 74,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 74,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 74,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 74,
                'char' => 59,
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
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 75,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'templates',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 75,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 75,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 75,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 75,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 79,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 79,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'template',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 79,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 79,
                'char' => 27,
              ),
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
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 80,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'template',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 80,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 80,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 81,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 84,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => 'The field :field is not valid for ',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 84,
                  'char' => 51,
                ),
                'right' => 
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
                        'value' => 'this',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 84,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 84,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 84,
                  'char' => 68,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 84,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 85,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Get the template message
    *
    * @return string
    * @throw InvalidArgumentException When the field does not exists
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 72,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 72,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 71,
          'last-line' => 91,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTemplates',
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
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 94,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'templates',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 94,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 94,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Get templates collection object
    *
    * @return array
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 93,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 93,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 92,
          'last-line' => 101,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTemplates',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'templates',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 102,
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
                  'variable' => 'field',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 104,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'template',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 104,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 106,
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
                  'property' => 'templates',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 106,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 106,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 108,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'templates',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 108,
                'char' => 42,
              ),
              'key' => 'field',
              'value' => 'template',
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
                      'variable' => 'field',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 109,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 109,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 109,
                      'char' => 56,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'template',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'template',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 110,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 110,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 110,
                      'char' => 59,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'templates',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 111,
                          'char' => 38,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'template',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 111,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 111,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 112,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 114,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 114,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 115,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Clear current templates and set new from an array,
    *
    * @return Validator
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
                  'value' => 'ValidatorInterface',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 103,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 102,
          'last-line' => 121,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTemplate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'template',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 122,
              'char' => 49,
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
                  'property' => 'template',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'template',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 124,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 124,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 126,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 126,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 127,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Set a new template message
    *
    * @return Validator
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
                  'value' => 'ValidatorInterface',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 123,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 123,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 123,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 122,
          'last-line' => 132,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 133,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 133,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 133,
              'char' => 67,
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
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 135,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'fieldValue',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 135,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 137,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 137,
                    'char' => 45,
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
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 137,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 137,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 137,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 137,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 137,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 137,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 137,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 138,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 139,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 145,
              'char' => 10,
            ),
            2 => 
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
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 145,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'attribute',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 145,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 145,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 145,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 145,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 145,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 145,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 145,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fieldValue',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 146,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 146,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 146,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 146,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 146,
                    'char' => 45,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'fieldValue',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 147,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 148,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 149,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 151,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 151,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 152,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an option in the validator\'s options
     * Returns null if the option hasn\'t set
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 134,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 134,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 133,
          'last-line' => 156,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 157,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
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
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 159,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 159,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 159,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 159,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 159,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 159,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 160,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if an option is defined
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 158,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 158,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 157,
          'last-line' => 164,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 165,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 165,
              'char' => 49,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 167,
                      'char' => 30,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 167,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 167,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 168,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets an option in the validator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 166,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 165,
          'last-line' => 172,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 173,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 173,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 173,
              'char' => 73,
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 173,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 173,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 173,
          'last-line' => 177,
          'char' => 28,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'prepareCode',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 178,
              'char' => 49,
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
                  'variable' => 'code',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 180,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 182,
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
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 182,
                      'char' => 25,
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
                          'value' => 'code',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 182,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 182,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 182,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 182,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 184,
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
                    'value' => 'code',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 184,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 184,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 184,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 184,
                'char' => 33,
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
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'code',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 185,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 185,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 185,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 185,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 186,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 188,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 188,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 189,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prepares a validation code.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 178,
                'char' => 58,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 179,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 179,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 178,
          'last-line' => 193,
          'char' => 22,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'prepareLabel',
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 194,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 194,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 194,
              'char' => 75,
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
                  'variable' => 'label',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 196,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 198,
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
                  'variable' => 'label',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 198,
                      'char' => 26,
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
                          'value' => 'label',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 198,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 198,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 198,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 198,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 200,
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
                    'value' => 'label',
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 200,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 200,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 200,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 200,
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
                      'variable' => 'label',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'label',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 201,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 201,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 201,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 201,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 202,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 204,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'label',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 204,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 204,
                'char' => 24,
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
                      'variable' => 'label',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validation',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 205,
                          'char' => 36,
                        ),
                        'name' => 'getLabel',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 205,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 205,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 205,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 205,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 206,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 208,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'label',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 208,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 209,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prepares a label for the field.
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 195,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 195,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 194,
          'last-line' => 217,
          'char' => 22,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'messageFactory',
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
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 218,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 218,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 218,
              'char' => 70,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'replacements',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 218,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 218,
              'char' => 96,
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
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 220,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 222,
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
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 222,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 222,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 222,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 222,
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
                        'type' => 'fcall',
                        'name' => 'implode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => ', ',
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 223,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 223,
                            'char' => 41,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 223,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 223,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 223,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 223,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 224,
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
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 224,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 224,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 224,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 224,
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
                          'variable' => 'singleField',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 225,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 225,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 226,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 226,
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
                          'value' => 'The field can not be printed',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 227,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 227,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 227,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 228,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 230,
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
                  'variable' => 'replacements',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_merge',
                    'call-type' => 1,
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
                                'value' => ':field',
                                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                'line' => 232,
                                'char' => 24,
                              ),
                              'value' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                  'line' => 232,
                                  'char' => 31,
                                ),
                                'name' => 'prepareLabel',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'validation',
                                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                      'line' => 232,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                    'line' => 232,
                                    'char' => 55,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'singleField',
                                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                      'line' => 232,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                    'line' => 232,
                                    'char' => 68,
                                  ),
                                ),
                                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                'line' => 233,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 233,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 233,
                          'char' => 14,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 233,
                        'char' => 14,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'replacements',
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 235,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 235,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 235,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 235,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 237,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Message',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strtr',
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
                              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                              'line' => 238,
                              'char' => 24,
                            ),
                            'name' => 'getTemplate',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'singleField',
                                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                  'line' => 238,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                                'line' => 238,
                                'char' => 48,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 238,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 238,
                          'char' => 49,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'replacements',
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 238,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 238,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 238,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 238,
                    'char' => 64,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'field',
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 239,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 239,
                    'char' => 18,
                  ),
                  2 => 
                  array (
                    'parameter' => 
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
                            'value' => 'this',
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 240,
                            'char' => 27,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 240,
                          'char' => 27,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 240,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 240,
                    'char' => 28,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                        'line' => 241,
                        'char' => 18,
                      ),
                      'name' => 'prepareCode',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'singleField',
                            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                            'line' => 241,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                          'line' => 241,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                      'line' => 242,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                    'line' => 242,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 242,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidator.zep',
              'line' => 243,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Create a default message by factory
    *
    * @return Message
    *
    * @throw Exception
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
                  'value' => 'Message',
                  'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                  'line' => 219,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/AbstractValidator.zep',
                'line' => 219,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidator.zep',
            'line' => 219,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidator.zep',
          'line' => 218,
          'last-line' => 244,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/AbstractValidator.zep',
      'line' => 23,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Validation/AbstractValidator.zep',
    'line' => 23,
    'char' => 14,
  ),
);