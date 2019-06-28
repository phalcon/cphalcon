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
    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation',
    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
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
        'name' => 'Phalcon\\Validation\\Validation',
        'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This is a base class for combined fields validators
 *',
    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
    'line' => 18,
    'char' => 8,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'AbstractValidatorComposite',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'AbstractValidator',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ValidatorCompositeInterface',
        'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
        'line' => 19,
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
          'name' => 'validators',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
            'line' => 23,
            'char' => 31,
          ),
          'docblock' => '**
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
              'line' => 23,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
          'line' => 27,
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
                'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                'line' => 28,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
              'line' => 28,
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
              'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
              'line' => 28,
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
                  'variable' => 'validator',
                  'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                  'line' => 30,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
              'line' => 32,
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
                  'type' => 'identical',
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                            'line' => 32,
                            'char' => 32,
                          ),
                          'name' => 'getValidators',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                          'line' => 32,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                        'line' => 32,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                    'line' => 32,
                    'char' => 52,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                    'line' => 32,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                  'line' => 32,
                  'char' => 56,
                ),
                'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                'line' => 32,
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
                          'type' => 'concat',
                          'left' => 
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
                                  'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                                  'line' => 33,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                                'line' => 33,
                                'char' => 47,
                              ),
                            ),
                            'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                            'line' => 33,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' does not have any validator added',
                            'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                            'line' => 33,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                          'line' => 33,
                          'char' => 85,
                        ),
                        'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                        'line' => 33,
                        'char' => 85,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                    'line' => 33,
                    'char' => 86,
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                  'line' => 34,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
              'line' => 36,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                  'line' => 36,
                  'char' => 31,
                ),
                'name' => 'getValidators',
                'call-type' => 1,
                'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                'line' => 36,
                'char' => 48,
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
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'validator',
                        'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                        'line' => 37,
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
                            'value' => 'validation',
                            'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                            'line' => 37,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                          'line' => 37,
                          'char' => 46,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                            'line' => 37,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                          'line' => 37,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                      'line' => 37,
                      'char' => 57,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                      'line' => 37,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                    'line' => 37,
                    'char' => 65,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                        'line' => 38,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                      'line' => 39,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                  'line' => 40,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
              'line' => 42,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                'line' => 42,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
              'line' => 43,
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
                'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
                'line' => 29,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
            'line' => 29,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
          'line' => 28,
          'last-line' => 44,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
      'line' => 18,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Validation/AbstractValidatorComposite.zep',
    'line' => 18,
    'char' => 14,
  ),
);