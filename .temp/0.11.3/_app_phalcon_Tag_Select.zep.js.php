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
    'file' => '/app/phalcon/Tag/Select.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Tag',
    'file' => '/app/phalcon/Tag/Select.zep',
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
        'name' => 'Phalcon\\Tag\\Exception',
        'file' => '/app/phalcon/Tag/Select.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Tag/Select.zep',
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
        'name' => 'Phalcon\\Tag',
        'alias' => 'BaseTag',
        'file' => '/app/phalcon/Tag/Select.zep',
        'line' => 14,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Tag/Select.zep',
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
        'name' => 'Phalcon\\EscaperInterface',
        'file' => '/app/phalcon/Tag/Select.zep',
        'line' => 15,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Tag/Select.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\ResulsetInterface',
        'file' => '/app/phalcon/Tag/Select.zep',
        'line' => 16,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Tag/Select.zep',
    'line' => 23,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Tag\\Select
 *
 * Generates a SELECT html tag using a static array of values or a
 * Phalcon\\Mvc\\Model resultset
 *',
    'file' => '/app/phalcon/Tag/Select.zep',
    'line' => 24,
    'char' => 8,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Select',
    'abstract' => 1,
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
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'selectField',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 32,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 32,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 32,
              'char' => 63,
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
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'id',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 29,
                ),
                3 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 36,
                ),
                4 => 
                array (
                  'variable' => 'useEmpty',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 46,
                ),
                5 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 52,
                ),
                6 => 
                array (
                  'variable' => 'emptyValue',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 64,
                ),
                7 => 
                array (
                  'variable' => 'emptyText',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 34,
                  'char' => 75,
                ),
                8 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 35,
                  'char' => 20,
                ),
                9 => 
                array (
                  'variable' => 'using',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 35,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 37,
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
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 37,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 37,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 37,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 37,
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
                      'variable' => 'params',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 38,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 38,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 38,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 38,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 38,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 38,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 39,
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
                      'variable' => 'params',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 40,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 40,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 41,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 43,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'id',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 43,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 43,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 43,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 43,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 43,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 43,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 44,
                          'char' => 25,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 44,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 44,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 44,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 44,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 45,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 50,
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
                  'type' => 'fcall',
                  'name' => 'memstr',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 50,
                        'char' => 22,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 50,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '[',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 50,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 50,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 50,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 50,
                'char' => 27,
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
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 51,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 51,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 51,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 51,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 51,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 52,
                              'char' => 30,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 52,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 52,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 53,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 54,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 56,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 56,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 56,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 56,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 56,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 56,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 56,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'params',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 57,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 57,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 57,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 58,
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
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 59,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 59,
                    'char' => 22,
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
                              'value' => 'name',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 60,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 60,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 60,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 61,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 62,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 64,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 64,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 64,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 64,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 64,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 64,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 64,
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
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'BaseTag',
                        'dynamic' => 0,
                        'name' => 'getValue',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 65,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 65,
                            'char' => 45,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 65,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 65,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 65,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 65,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 67,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 67,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 67,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 68,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 70,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'useEmpty',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 70,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 70,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'useEmpty',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 70,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 70,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 70,
                'char' => 45,
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
                      'type' => 'fetch',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'emptyValue',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 71,
                        'char' => 54,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 71,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'emptyValue',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 71,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 71,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 71,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 71,
                    'char' => 54,
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
                          'variable' => 'emptyValue',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 72,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 72,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 73,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 74,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'emptyValue',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 74,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 74,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 75,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 77,
                  'char' => 14,
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
                        'value' => 'emptyText',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 77,
                        'char' => 52,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 77,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'emptyText',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 77,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 77,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 77,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 77,
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
                          'variable' => 'emptyText',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'Choose...',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 78,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 78,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 79,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
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
                          'value' => 'params',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 80,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'emptyText',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 80,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 80,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 81,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 83,
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
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 83,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'useEmpty',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 83,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 83,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 86,
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
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 86,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 86,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 86,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 86,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 86,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 86,
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
                      'variable' => 'options',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 87,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 87,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 90,
              'char' => 10,
            ),
            8 => 
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
                    'value' => 'options',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 90,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 90,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 90,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 90,
                'char' => 37,
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
                          'value' => 'using',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 94,
                          'char' => 53,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'params',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 94,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'using',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 94,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 94,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 94,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 94,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 94,
                    'char' => 53,
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
                              'value' => 'The \'using\' parameter is required',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 95,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 95,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 95,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 96,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 98,
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
                              'value' => 'using',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 98,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 98,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 98,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 98,
                          'char' => 49,
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
                              'value' => 'using',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 98,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 98,
                            'char' => 65,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 98,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 98,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 98,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 98,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 98,
                    'char' => 75,
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
                              'value' => 'The \'using\' parameter should be an array',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 101,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 101,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 101,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 102,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 103,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 105,
              'char' => 13,
            ),
            9 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 105,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'using',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 105,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 105,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 107,
              'char' => 11,
            ),
            10 => 
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
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'BaseTag',
                        'dynamic' => 0,
                        'name' => 'renderAttributes',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '<select',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 107,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 107,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 107,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 107,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 107,
                        'char' => 63,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 107,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 107,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'PHP_EOL',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 107,
                      'char' => 76,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 107,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 107,
                  'char' => 76,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 109,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'useEmpty',
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 109,
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
                      'operator' => 'concat-assign',
                      'variable' => 'code',
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
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\\t<option value=\\"',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 113,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'emptyValue',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 113,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 113,
                                'char' => 56,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\\">',
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 113,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 113,
                              'char' => 62,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'emptyText',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 113,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 113,
                            'char' => 74,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '</option>',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 113,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 113,
                          'char' => 86,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 113,
                          'char' => 95,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 113,
                        'char' => 95,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 113,
                      'char' => 95,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 114,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 116,
              'char' => 10,
            ),
            12 => 
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
                    'value' => 'options',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 116,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 116,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 116,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 116,
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
                      'operator' => 'concat-assign',
                      'variable' => 'code',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'optionsFromResultset',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 121,
                              'char' => 24,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 121,
                            'char' => 24,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'using',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 122,
                              'char' => 22,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 122,
                            'char' => 22,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 123,
                              'char' => 22,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 123,
                            'char' => 22,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => '</option>',
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 124,
                                'char' => 27,
                              ),
                              'right' => 
                              array (
                                'type' => 'constant',
                                'value' => 'PHP_EOL',
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 125,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 125,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 125,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 125,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 125,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 126,
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
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 127,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 127,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 127,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 127,
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
                          'operator' => 'concat-assign',
                          'variable' => 'code',
                          'expr' => 
                          array (
                            'type' => 'scall',
                            'dynamic-class' => 0,
                            'class' => 'self',
                            'dynamic' => 0,
                            'name' => 'optionsFromArray',
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'options',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 132,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 132,
                                'char' => 28,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 133,
                                  'char' => 26,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 133,
                                'char' => 26,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '</option>',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 134,
                                    'char' => 31,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'constant',
                                    'value' => 'PHP_EOL',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 135,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 135,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 135,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 135,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 135,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 136,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 137,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 139,
              'char' => 11,
            ),
            13 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '</select>',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 139,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 139,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 141,
              'char' => 14,
            ),
            14 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 141,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 142,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a SELECT tag
     *
     * @param array parameters
     * @param array data
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
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 33,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag/Select.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag/Select.zep',
          'line' => 32,
          'last-line' => 146,
          'char' => 26,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'optionsFromArray',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 147,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 147,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'closeOption',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 147,
              'char' => 87,
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
                  'variable' => 'strValue',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 149,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'strOptionValue',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 149,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 149,
                  'char' => 43,
                ),
                3 => 
                array (
                  'variable' => 'optionValue',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 149,
                  'char' => 56,
                ),
                4 => 
                array (
                  'variable' => 'optionText',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 149,
                  'char' => 68,
                ),
                5 => 
                array (
                  'variable' => 'escaped',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 149,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 151,
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
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 151,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 151,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 153,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 153,
                'char' => 45,
              ),
              'key' => 'optionValue',
              'value' => 'optionText',
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
                      'variable' => 'escaped',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'htmlspecialchars',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'optionValue',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 154,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 154,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 154,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 154,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 156,
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
                        'value' => 'optionText',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 156,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 156,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 156,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 156,
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
                          'operator' => 'concat-assign',
                          'variable' => 'code',
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
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<optgroup label=\\"',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 157,
                                        'char' => 49,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'escaped',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 157,
                                        'char' => 59,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 157,
                                      'char' => 59,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 157,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 157,
                                    'char' => 65,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'constant',
                                    'value' => 'PHP_EOL',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 157,
                                    'char' => 75,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 157,
                                  'char' => 75,
                                ),
                                'right' => 
                                array (
                                  'type' => 'scall',
                                  'dynamic-class' => 0,
                                  'class' => 'self',
                                  'dynamic' => 0,
                                  'name' => 'optionsFromArray',
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 157,
                                        'char' => 110,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 157,
                                      'char' => 110,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'value',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 157,
                                        'char' => 117,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 157,
                                      'char' => 117,
                                    ),
                                    2 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'closeOption',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 157,
                                        'char' => 130,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 157,
                                      'char' => 130,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 157,
                                  'char' => 132,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 157,
                                'char' => 132,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\\t</optgroup>',
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 157,
                                'char' => 148,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 157,
                              'char' => 148,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 157,
                              'char' => 157,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 157,
                            'char' => 157,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 157,
                          'char' => 157,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 159,
                      'char' => 24,
                    ),
                    1 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 160,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 162,
                  'char' => 14,
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
                        'value' => 'value',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 162,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 162,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 162,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 162,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
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
                              'value' => 'optionValue',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 163,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 163,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 163,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 163,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 163,
                        'char' => 49,
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
                              'operator' => 'concat-assign',
                              'variable' => 'code',
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 164,
                                        'char' => 73,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'escaped',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 164,
                                        'char' => 83,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 164,
                                      'char' => 83,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 164,
                                      'char' => 89,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 164,
                                    'char' => 89,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 164,
                                    'char' => 102,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 164,
                                  'char' => 102,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 164,
                                  'char' => 115,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 164,
                                'char' => 115,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 164,
                              'char' => 115,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 165,
                          'char' => 17,
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
                              'operator' => 'concat-assign',
                              'variable' => 'code',
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<option value=\\"',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 166,
                                        'char' => 51,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'escaped',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 166,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 166,
                                      'char' => 61,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 166,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 166,
                                    'char' => 67,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 166,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 166,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 166,
                                  'char' => 93,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 166,
                                'char' => 93,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 166,
                              'char' => 93,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 167,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 168,
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
                          'variable' => 'strOptionValue',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'string',
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'optionValue',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 169,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 169,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 169,
                          'char' => 58,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'strValue',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'string',
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 170,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 170,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 170,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 172,
                      'char' => 18,
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
                          'value' => 'strOptionValue',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 172,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'strValue',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 172,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 172,
                        'char' => 48,
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
                              'operator' => 'concat-assign',
                              'variable' => 'code',
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 173,
                                        'char' => 73,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'escaped',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 173,
                                        'char' => 83,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 173,
                                      'char' => 83,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 173,
                                      'char' => 89,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 173,
                                    'char' => 89,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 173,
                                    'char' => 102,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 173,
                                  'char' => 102,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 173,
                                  'char' => 115,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 173,
                                'char' => 115,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 173,
                              'char' => 115,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 174,
                          'char' => 17,
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
                              'operator' => 'concat-assign',
                              'variable' => 'code',
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<option value=\\"',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 175,
                                        'char' => 51,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'escaped',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 175,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 175,
                                      'char' => 61,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 175,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 175,
                                    'char' => 67,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 175,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 175,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 175,
                                  'char' => 93,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 175,
                                'char' => 93,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 175,
                              'char' => 93,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 176,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 177,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 178,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 180,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 180,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 181,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generate the OPTION tags based on an array
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
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 148,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag/Select.zep',
            'line' => 148,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag/Select.zep',
          'line' => 147,
          'last-line' => 187,
          'char' => 27,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'optionsFromResultset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'resultset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ResulsetInterface',
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 189,
                'char' => 37,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 189,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'using',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 190,
              'char' => 18,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 191,
              'char' => 18,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'closeOption',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 193,
              'char' => 5,
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
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 195,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 195,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'option',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 195,
                  'char' => 33,
                ),
                3 => 
                array (
                  'variable' => 'usingZero',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 195,
                  'char' => 44,
                ),
                4 => 
                array (
                  'variable' => 'usingOne',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 195,
                  'char' => 54,
                ),
                5 => 
                array (
                  'variable' => 'escaper',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 195,
                  'char' => 63,
                ),
                6 => 
                array (
                  'variable' => 'optionValue',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 195,
                  'char' => 76,
                ),
                7 => 
                array (
                  'variable' => 'optionText',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 196,
                  'char' => 23,
                ),
                8 => 
                array (
                  'variable' => 'strValue',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 196,
                  'char' => 33,
                ),
                9 => 
                array (
                  'variable' => 'strOptionValue',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 196,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
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
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 198,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 198,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 199,
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
                    'type' => 'null',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 199,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 199,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 201,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'using',
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 201,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 201,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 201,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 201,
                'char' => 34,
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
                              'value' => 'using',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 202,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 202,
                            'char' => 36,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 202,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '2',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 202,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 202,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 202,
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
                              'value' => 'Parameter \'using\' requires two values',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 203,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 203,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 203,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 204,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
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
                      'variable' => 'usingZero',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'using',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 206,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 206,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 206,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 206,
                      'char' => 37,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'usingOne',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'using',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 207,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 207,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 207,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 207,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 208,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 210,
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
                  'variable' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'EscaperInterface',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 210,
                      'char' => 70,
                    ),
                    'right' => 
                    array (
                      'type' => 'scall',
                      'dynamic-class' => 0,
                      'class' => 'BaseTag',
                      'dynamic' => 0,
                      'name' => 'getEscaperService',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 210,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 210,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 210,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 212,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'iterator',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 212,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 212,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 212,
                'char' => 43,
              ),
              'value' => 'option',
              'reverse' => 0,
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
                        'value' => 'using',
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 213,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 213,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 213,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Tag/Select.zep',
                    'line' => 213,
                    'char' => 38,
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
                            'value' => 'option',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 214,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 214,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 214,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 214,
                        'char' => 44,
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
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 215,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 215,
                                'char' => 44,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'readAttribute',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 215,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 215,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 215,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'optionValue',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 216,
                                      'char' => 50,
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
                                          'value' => 'usingZero',
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 216,
                                          'char' => 74,
                                        ),
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 216,
                                        'char' => 74,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 216,
                                    'char' => 75,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 216,
                                  'char' => 75,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 217,
                              'char' => 27,
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
                                  'variable' => 'optionText',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 217,
                                      'char' => 49,
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
                                          'value' => 'usingOne',
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 217,
                                          'char' => 72,
                                        ),
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 217,
                                        'char' => 72,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 217,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 217,
                                  'char' => 73,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 218,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'optionValue',
                                  'expr' => 
                                  array (
                                    'type' => 'property-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 219,
                                      'char' => 50,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'usingZero',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 219,
                                      'char' => 60,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 219,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 219,
                                  'char' => 60,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 220,
                              'char' => 27,
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
                                  'variable' => 'optionText',
                                  'expr' => 
                                  array (
                                    'type' => 'property-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 220,
                                      'char' => 49,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'usingOne',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 220,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 220,
                                    'char' => 58,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 220,
                                  'char' => 58,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 221,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 222,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
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
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 223,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 223,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'array',
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 223,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 223,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 223,
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
                                      'value' => 'Resultset returned an invalid value',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 226,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 226,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 226,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 227,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 229,
                          'char' => 23,
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
                              'variable' => 'optionValue',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 229,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'usingZero',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 229,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 229,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 229,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 230,
                          'char' => 23,
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
                              'variable' => 'optionText',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 230,
                                  'char' => 44,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'usingOne',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 230,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 230,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 230,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 231,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 233,
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
                          'variable' => 'optionValue',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'escaper',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 233,
                              'char' => 43,
                            ),
                            'name' => 'escapeHtmlAttr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionValue',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 233,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 233,
                                'char' => 70,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 233,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 233,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 234,
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
                          'variable' => 'optionText',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'escaper',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 234,
                              'char' => 42,
                            ),
                            'name' => 'escapeHtml',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionText',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 234,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 234,
                                'char' => 64,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 234,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 234,
                          'char' => 65,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 240,
                      'char' => 18,
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
                            'value' => 'value',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 240,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 240,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 240,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 240,
                        'char' => 42,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
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
                                  'value' => 'optionValue',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 241,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 241,
                                'char' => 44,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 241,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 241,
                                'char' => 51,
                              ),
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 241,
                            'char' => 53,
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'code',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 242,
                                            'char' => 77,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'optionValue',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 242,
                                            'char' => 91,
                                          ),
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 242,
                                          'char' => 91,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 242,
                                          'char' => 97,
                                        ),
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 242,
                                        'char' => 97,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 242,
                                        'char' => 110,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 242,
                                      'char' => 110,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 242,
                                      'char' => 123,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 242,
                                    'char' => 123,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 242,
                                  'char' => 123,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 243,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'code',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option value=\\"',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 244,
                                            'char' => 55,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'optionValue',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 244,
                                            'char' => 69,
                                          ),
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 244,
                                          'char' => 69,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 244,
                                          'char' => 75,
                                        ),
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 244,
                                        'char' => 75,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 244,
                                        'char' => 88,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 244,
                                      'char' => 88,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 244,
                                      'char' => 101,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 244,
                                    'char' => 101,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 244,
                                  'char' => 101,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 245,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 246,
                          'char' => 17,
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
                              'variable' => 'strOptionValue',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'string',
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionValue',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 247,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 247,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 247,
                              'char' => 62,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'strValue',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'string',
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 248,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 248,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 248,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 250,
                          'char' => 22,
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
                              'value' => 'strOptionValue',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 250,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'strValue',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 250,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 250,
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'code',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 251,
                                            'char' => 77,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'strOptionValue',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 251,
                                            'char' => 94,
                                          ),
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 251,
                                          'char' => 94,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 251,
                                          'char' => 100,
                                        ),
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 251,
                                        'char' => 100,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 251,
                                        'char' => 113,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 251,
                                      'char' => 113,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 251,
                                      'char' => 126,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 251,
                                    'char' => 126,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 251,
                                  'char' => 126,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 252,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'code',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option value=\\"',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 253,
                                            'char' => 55,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'strOptionValue',
                                            'file' => '/app/phalcon/Tag/Select.zep',
                                            'line' => 253,
                                            'char' => 72,
                                          ),
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 253,
                                          'char' => 72,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Tag/Select.zep',
                                          'line' => 253,
                                          'char' => 78,
                                        ),
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 253,
                                        'char' => 78,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Tag/Select.zep',
                                        'line' => 253,
                                        'char' => 91,
                                      ),
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 253,
                                      'char' => 91,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 253,
                                      'char' => 104,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 253,
                                    'char' => 104,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 253,
                                  'char' => 104,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 254,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 255,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 256,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
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
                            'value' => 'using',
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 261,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 261,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 261,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Tag/Select.zep',
                        'line' => 261,
                        'char' => 43,
                      ),
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
                              'value' => 'params',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 262,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 262,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Tag/Select.zep',
                            'line' => 262,
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
                                  'variable' => 'params',
                                  'expr' => 
                                  array (
                                    'type' => 'empty-array',
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 263,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 263,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 264,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 266,
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
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Tag/Select.zep',
                                  'line' => 266,
                                  'char' => 33,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'option',
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 266,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 266,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 267,
                          'char' => 23,
                        ),
                        2 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'concat-assign',
                              'variable' => 'code',
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
                                      'value' => 'using',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 267,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 267,
                                    'char' => 58,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'params',
                                      'file' => '/app/phalcon/Tag/Select.zep',
                                      'line' => 267,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Tag/Select.zep',
                                    'line' => 267,
                                    'char' => 66,
                                  ),
                                ),
                                'file' => '/app/phalcon/Tag/Select.zep',
                                'line' => 267,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Tag/Select.zep',
                              'line' => 267,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Tag/Select.zep',
                          'line' => 268,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Tag/Select.zep',
                      'line' => 269,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Tag/Select.zep',
                  'line' => 270,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 272,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'code',
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 272,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Tag/Select.zep',
              'line' => 273,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generate the OPTION tags based on a resultset
     *
     * @param array using
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
                'file' => '/app/phalcon/Tag/Select.zep',
                'line' => 194,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Tag/Select.zep',
            'line' => 194,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Tag/Select.zep',
          'line' => 188,
          'last-line' => 274,
          'char' => 27,
        ),
      ),
      'file' => '/app/phalcon/Tag/Select.zep',
      'line' => 24,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Tag/Select.zep',
    'line' => 24,
    'char' => 14,
  ),
);