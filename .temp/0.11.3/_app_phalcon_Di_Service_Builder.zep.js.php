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
    'file' => '/app/phalcon/Di/Service/Builder.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di\\Service',
    'file' => '/app/phalcon/Di/Service/Builder.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Di/Service/Builder.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Di/Service/Builder.zep',
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
        'name' => 'Phalcon\\Di\\Exception',
        'file' => '/app/phalcon/Di/Service/Builder.zep',
        'line' => 14,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Di/Service/Builder.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Di\\Service\\Builder
 *
 * This class builds instances based on complex definitions
 *',
    'file' => '/app/phalcon/Di/Service/Builder.zep',
    'line' => 21,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Builder',
    'abstract' => 0,
    'final' => 0,
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
          'name' => 'build',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 29,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 29,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 29,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 29,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 29,
              'char' => 88,
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
                  'variable' => 'className',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 31,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'arguments',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 31,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'paramCalls',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 31,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'methodPosition',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 31,
                  'char' => 61,
                ),
                4 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 31,
                  'char' => 69,
                ),
                5 => 
                array (
                  'variable' => 'methodName',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 32,
                  'char' => 23,
                ),
                6 => 
                array (
                  'variable' => 'methodCall',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 32,
                  'char' => 35,
                ),
                7 => 
                array (
                  'variable' => 'instance',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 32,
                  'char' => 45,
                ),
                8 => 
                array (
                  'variable' => 'propertyPosition',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 32,
                  'char' => 63,
                ),
                9 => 
                array (
                  'variable' => 'property',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 32,
                  'char' => 73,
                ),
                10 => 
                array (
                  'variable' => 'propertyName',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 33,
                  'char' => 25,
                ),
                11 => 
                array (
                  'variable' => 'propertyValue',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 33,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 38,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'className',
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 38,
                      'char' => 61,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 38,
                        'char' => 49,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'className',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 38,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 38,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 38,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 38,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 38,
                'char' => 61,
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
                          'value' => 'Invalid service definition. Missing \'className\' parameter',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 41,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 41,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 41,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 42,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 44,
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
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 44,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 44,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 44,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 44,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 50,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 50,
                        'char' => 32,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 50,
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
                          'variable' => 'instance',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'create_instance_params',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 51,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 51,
                                'char' => 64,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parameters',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 51,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 51,
                                'char' => 76,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 51,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 51,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 52,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'instance',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'create_instance',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 53,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 53,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 53,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 53,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 54,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 56,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'value' => 'arguments',
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 61,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 61,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'arguments',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 61,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 61,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 61,
                    'char' => 55,
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
                          'variable' => 'instance',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'create_instance_params',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 67,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 67,
                                'char' => 30,
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
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 68,
                                    'char' => 26,
                                  ),
                                  'name' => 'buildParameters',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'container',
                                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                                        'line' => 68,
                                        'char' => 52,
                                      ),
                                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                                      'line' => 68,
                                      'char' => 52,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'arguments',
                                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                                        'line' => 68,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                                      'line' => 68,
                                      'char' => 63,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 69,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 69,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 69,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 69,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 71,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'instance',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'create_instance',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 72,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 72,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 72,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 72,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 73,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 74,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 79,
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
                  'value' => 'paramCalls',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 79,
                  'char' => 48,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 79,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'calls',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 79,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 79,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 79,
                'char' => 48,
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
                          'value' => 'instance',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 80,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 80,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 80,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 80,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 80,
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
                              'value' => 'The definition has setter injection parameters but the constructor didn\'t return an instance',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 83,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 83,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 83,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 84,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 86,
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
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paramCalls',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 86,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 86,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 86,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 86,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 86,
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
                              'value' => 'Setter injection parameters must be an array',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 89,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 89,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 89,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 90,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 95,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paramCalls',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 95,
                    'char' => 54,
                  ),
                  'key' => 'methodPosition',
                  'value' => 'method',
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
                              'value' => 'method',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 100,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 100,
                            'char' => 44,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 100,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 100,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 100,
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
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Method call must be an array on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 102,
                                    'char' => 67,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'methodPosition',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 103,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 103,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 103,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 103,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 104,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 109,
                      'char' => 18,
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
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'methodName',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 109,
                              'char' => 63,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'method',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 109,
                                'char' => 54,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'method',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 109,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 109,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 109,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 109,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 109,
                        'char' => 63,
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
                                    'type' => 'string',
                                    'value' => 'The method name is required on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 111,
                                    'char' => 66,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'methodPosition',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 112,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 112,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 112,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 112,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 113,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 118,
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
                          'variable' => 'methodCall',
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
                                  'value' => 'instance',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 118,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 118,
                                'char' => 43,
                              ),
                              1 => 
                              array (
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'methodName',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 118,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 118,
                                'char' => 55,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 118,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 118,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 120,
                      'char' => 18,
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
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 120,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'method',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 120,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'arguments',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 120,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 120,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 120,
                        'char' => 55,
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
                                  'value' => 'arguments',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 121,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 121,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'array',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 121,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 121,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 121,
                            'char' => 59,
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
                                        'type' => 'string',
                                        'value' => 'Call arguments must be an array ',
                                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                                        'line' => 123,
                                        'char' => 62,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'methodPosition',
                                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                                        'line' => 124,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                                      'line' => 124,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 124,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 124,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 125,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 127,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
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
                                  'value' => 'arguments',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 127,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 127,
                                'char' => 39,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 127,
                            'char' => 41,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'fcall',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'call_user_func_array',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'methodCall',
                                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                                      'line' => 132,
                                      'char' => 39,
                                    ),
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 132,
                                    'char' => 39,
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
                                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                                        'line' => 133,
                                        'char' => 34,
                                      ),
                                      'name' => 'buildParameters',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'container',
                                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                                            'line' => 133,
                                            'char' => 60,
                                          ),
                                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                                          'line' => 133,
                                          'char' => 60,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'arguments',
                                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                                            'line' => 133,
                                            'char' => 71,
                                          ),
                                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                                          'line' => 133,
                                          'char' => 71,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                                      'line' => 134,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 134,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 134,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 139,
                              'char' => 32,
                            ),
                            1 => 
                            array (
                              'type' => 'continue',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 140,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 141,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 146,
                      'char' => 30,
                    ),
                    4 => 
                    array (
                      'type' => 'fcall',
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
                              'value' => 'methodCall',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 146,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 146,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 146,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 147,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 148,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 153,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'paramCalls',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 153,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 153,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'properties',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 153,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 153,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 153,
                'char' => 53,
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
                          'value' => 'instance',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 155,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 155,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 155,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 155,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 155,
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
                              'value' => 'The definition has properties injection parameters but the constructor didn\'t return an instance',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 158,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 158,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 158,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 159,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 161,
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
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paramCalls',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 161,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 161,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 161,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 161,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 161,
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
                              'value' => 'Setter injection parameters must be an array',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 164,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 164,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 164,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 165,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 170,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paramCalls',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 170,
                    'char' => 58,
                  ),
                  'key' => 'propertyPosition',
                  'value' => 'property',
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
                              'value' => 'property',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 175,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 175,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 175,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 175,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 175,
                        'char' => 54,
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
                                    'type' => 'string',
                                    'value' => 'Property must be an array on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 177,
                                    'char' => 64,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'propertyPosition',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 178,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 178,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 178,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 178,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 179,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 184,
                      'char' => 18,
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
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'propertyName',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 184,
                              'char' => 65,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'property',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 184,
                                'char' => 58,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'name',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 184,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 184,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 184,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 184,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 184,
                        'char' => 65,
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
                                    'type' => 'string',
                                    'value' => 'The property name is required on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 186,
                                    'char' => 68,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'propertyPosition',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 187,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 187,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 187,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 187,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 188,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 193,
                      'char' => 18,
                    ),
                    2 => 
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
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'propertyValue',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 193,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'property',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 193,
                                'char' => 59,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'value',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 193,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 193,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 193,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 193,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 193,
                        'char' => 67,
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
                                    'type' => 'string',
                                    'value' => 'The property value is required on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 195,
                                    'char' => 69,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'propertyPosition',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 196,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 196,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 196,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 196,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 197,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 202,
                      'char' => 19,
                    ),
                    3 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-dynamic-object-property',
                          'operator' => 'assign',
                          'variable' => 'instance',
                          'property' => 'propertyName',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 202,
                              'char' => 53,
                            ),
                            'name' => 'buildParameter',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'container',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 203,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 203,
                                'char' => 30,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'propertyPosition',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 204,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 204,
                                'char' => 37,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'propertyValue',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 206,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 206,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 206,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 206,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 207,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 208,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 210,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'instance',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 210,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 211,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a service using a complex service definition
     *
     * @param array parameters
     * @return mixed
     *',
          'file' => '/app/phalcon/Di/Service/Builder.zep',
          'line' => 29,
          'last-line' => 217,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'buildParameter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 218,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 218,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 218,
              'char' => 74,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'argument',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 218,
              'char' => 91,
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
                  'variable' => 'type',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 220,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 220,
                  'char' => 23,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 220,
                  'char' => 30,
                ),
                3 => 
                array (
                  'variable' => 'instanceArguments',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 220,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 225,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 225,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'argument',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 225,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'type',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 225,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 225,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 225,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 225,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 225,
                'char' => 49,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Argument at position ',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 227,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'position',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 227,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 227,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' must have a type',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 228,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 228,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 228,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 228,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 229,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 231,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'type',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 231,
                'char' => 21,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'service',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 237,
                    'char' => 25,
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
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 238,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'argument',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 238,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'name',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 238,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 238,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 238,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 238,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 238,
                        'char' => 57,
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
                                    'type' => 'string',
                                    'value' => 'Service \'name\' is required in parameter on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 240,
                                    'char' => 78,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'position',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 241,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 241,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 241,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 241,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 242,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 244,
                      'char' => 18,
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
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 244,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 244,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 244,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 244,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 244,
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
                                  'value' => 'The dependency injector container is not valid',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 247,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 247,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 247,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 248,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 250,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 250,
                          'char' => 34,
                        ),
                        'name' => 'get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 250,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 250,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 250,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 255,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 255,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'parameter',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 255,
                    'char' => 27,
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
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 256,
                              'char' => 59,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'argument',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 256,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'value',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 256,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 256,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 256,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 256,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 256,
                        'char' => 59,
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
                                    'type' => 'string',
                                    'value' => 'Service \'value\' is required in parameter on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 258,
                                    'char' => 79,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'position',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 259,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 259,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 259,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 259,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 260,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 262,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 262,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 267,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 267,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'instance',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 267,
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
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 269,
                              'char' => 62,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'argument',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 269,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'className',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 269,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 269,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 269,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 269,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 269,
                        'char' => 62,
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
                                    'type' => 'string',
                                    'value' => 'Service \'className\' is required in parameter on position ',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 271,
                                    'char' => 83,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'position',
                                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                                    'line' => 272,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 272,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 272,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 272,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 273,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 275,
                      'char' => 18,
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
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 275,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 275,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 275,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 275,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 275,
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
                                  'value' => 'The dependency injector container is not valid',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 278,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 278,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 278,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 279,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 281,
                      'char' => 18,
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
                          'value' => 'instanceArguments',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 281,
                          'char' => 65,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'argument',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 281,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'arguments',
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 281,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 281,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 281,
                        'char' => 65,
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
                              'value' => 'container',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 285,
                              'char' => 38,
                            ),
                            'name' => 'get',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 285,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 285,
                                'char' => 47,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'instanceArguments',
                                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                                  'line' => 285,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 285,
                                'char' => 66,
                              ),
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 285,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 286,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 292,
                      'char' => 22,
                    ),
                    3 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 292,
                          'char' => 34,
                        ),
                        'name' => 'get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 292,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 292,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 292,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 294,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 294,
                  'char' => 19,
                ),
                3 => 
                array (
                  'type' => 'default',
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
                                'type' => 'string',
                                'value' => 'Unknown service type in parameter on position ',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 299,
                                'char' => 68,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'position',
                                'file' => '/app/phalcon/Di/Service/Builder.zep',
                                'line' => 300,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 300,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 300,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 300,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 301,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 301,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 302,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolves a constructor/call parameter
     *
     * @return mixed
     *',
          'file' => '/app/phalcon/Di/Service/Builder.zep',
          'line' => 218,
          'last-line' => 306,
          'char' => 20,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'buildParameters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 307,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 307,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 307,
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
                  'variable' => 'position',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 309,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'argument',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 309,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 310,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'buildArguments',
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 310,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 312,
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
                  'variable' => 'buildArguments',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Di/Service/Builder.zep',
                    'line' => 312,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 312,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 314,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'arguments',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 314,
                'char' => 45,
              ),
              'key' => 'position',
              'value' => 'argument',
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
                      'variable' => 'buildArguments',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Di/Service/Builder.zep',
                          'line' => 315,
                          'char' => 41,
                        ),
                        'name' => 'buildParameter',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 316,
                              'char' => 26,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 316,
                            'char' => 26,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'position',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 317,
                              'char' => 25,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 317,
                            'char' => 25,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'argument',
                              'file' => '/app/phalcon/Di/Service/Builder.zep',
                              'line' => 319,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Di/Service/Builder.zep',
                            'line' => 319,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service/Builder.zep',
                        'line' => 319,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Di/Service/Builder.zep',
                      'line' => 319,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service/Builder.zep',
                  'line' => 320,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 322,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'buildArguments',
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 322,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Di/Service/Builder.zep',
              'line' => 323,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolves an array of parameters
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
                'file' => '/app/phalcon/Di/Service/Builder.zep',
                'line' => 308,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Service/Builder.zep',
            'line' => 308,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service/Builder.zep',
          'line' => 307,
          'last-line' => 324,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Di/Service/Builder.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Di/Service/Builder.zep',
    'line' => 21,
    'char' => 5,
  ),
);