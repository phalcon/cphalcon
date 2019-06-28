<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Helper/Str.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Helper',
    'file' => '/app/phalcon/Helper/Str.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Helper/Str.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Helper/Str.zep',
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
        'name' => 'Phalcon\\Helper\\Exception',
        'file' => '/app/phalcon/Helper/Str.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Helper/Str.zep',
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
        'name' => 'RuntimeException',
        'file' => '/app/phalcon/Helper/Str.zep',
        'line' => 15,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Helper/Str.zep',
    'line' => 19,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class offers quick string functions throughout the framework
 *',
    'file' => '/app/phalcon/Helper/Str.zep',
    'line' => 20,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Str',
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
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'camelize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 45,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'delimiter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 45,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 45,
              'char' => 77,
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
                  'value' => 'text',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 47,
                  'char' => 21,
                ),
                'name' => 'camelize',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 47,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 47,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 47,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Converts strings to camelize style
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::camelize("coco_bongo");            // CocoBongo
     * echo Str::camelize("co_co-bon_go", "-");     // Co_coBon_go
     * echo Str::camelize("co_co-bon_go", "_-");    // CoCoBonGo
     * ```
     *
     * @param string $text
     * @param mixed  $delimiter
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 46,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 46,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 45,
          'last-line' => 72,
          'char' => 32,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'concat',
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
                  'variable' => 'argument',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'arguments',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'first',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 45,
                ),
                4 => 
                array (
                  'variable' => 'last',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 51,
                ),
                5 => 
                array (
                  'variable' => 'prefix',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 59,
                ),
                6 => 
                array (
                  'variable' => 'delimiter',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 70,
                ),
                7 => 
                array (
                  'variable' => 'suffix',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 75,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 77,
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
                  'variable' => 'arguments',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'func_get_args',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 77,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 77,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 79,
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
                  'type' => 'less',
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
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 79,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 79,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 79,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '3',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 79,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 79,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 79,
                'char' => 42,
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
                          'value' => 'concat needs at least three parameters',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 80,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 80,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 80,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 81,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 83,
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
                  'variable' => 'delimiter',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'first',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 83,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 83,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 83,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 83,
                  'char' => 46,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'arguments',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'sliceRight',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 84,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 84,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 84,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 84,
                  'char' => 51,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'first',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'first',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 85,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 85,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 85,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 85,
                  'char' => 46,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'last',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'last',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'arguments',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 86,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 86,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 86,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 86,
                  'char' => 45,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 87,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 87,
                  'char' => 25,
                ),
                5 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'suffix',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 88,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 88,
                  'char' => 25,
                ),
                6 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 89,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 89,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 91,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'startsWith',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'first',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 91,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 91,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 91,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 91,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 91,
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
                      'variable' => 'prefix',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'delimiter',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 92,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 92,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 95,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'self',
                'dynamic' => 0,
                'name' => 'endsWith',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'last',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 95,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 95,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 95,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 95,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 95,
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
                      'variable' => 'suffix',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'delimiter',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 96,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 96,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 97,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 100,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'arguments',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 100,
                'char' => 35,
              ),
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'trim',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'argument',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 101,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 101,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'delimiter',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 101,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 101,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 101,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 101,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 102,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 104,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 104,
                    'char' => 23,
                  ),
                  'right' => 
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
                          'type' => 'variable',
                          'value' => 'delimiter',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 104,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 104,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 104,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 104,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 104,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 104,
                  'char' => 50,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'suffix',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 104,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 104,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Concatenates strings using the separator only once without duplication in
     * places concatenation
     *
     * ```php
     * $str = Phalcon\\Helper\\Str::concat(
     *     "/",
     *     "/tmp/",
     *     "/folder_1/",
     *     "/folder_2",
     *     "folder_3/"
     * );
     *
     * echo $str;   // /tmp/folder_1/folder_2/folder_3/
     * ```
     *
     * @param string separator
     * @param string a
     * @param string b
     * @param string ...N
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 74,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 74,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 73,
          'last-line' => 114,
          'char' => 32,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'countVowels',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 115,
              'char' => 58,
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
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 117,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 119,
              'char' => 22,
            ),
            1 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'preg_match_all',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '/[aeiou]/i',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 119,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 119,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 119,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 119,
                    'char' => 40,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'matches',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 119,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 119,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 119,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 121,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
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
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'matches',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 121,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 121,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 121,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 121,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 121,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 122,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retuns number of vowels in provided string. Uses a regular expression
     * to count the number of vowels (A, E, I, O, U) in a string.
     *
     * @param string $string
     *
     * @return int
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 116,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 116,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 115,
          'last-line' => 134,
          'char' => 32,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'decapitalize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 136,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'upperRest',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 137,
                'char' => 31,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 137,
              'char' => 31,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'encoding',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'UTF-8',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 139,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 139,
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
                  'variable' => 'substr',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 141,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'suffix',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 141,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 143,
              'char' => 10,
            ),
            1 => 
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
                      'value' => 'mb_substr',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 143,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 143,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 143,
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
                      'variable' => 'substr',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'mb_substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 144,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 144,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 144,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 144,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 144,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 144,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 145,
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
                      'variable' => 'substr',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 146,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 146,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 146,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 146,
                            'char' => 40,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 146,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 146,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 147,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 149,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'upperRest',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 149,
                'char' => 22,
              ),
              'statements' => 
              array (
                0 => 
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
                          'value' => 'mb_strtoupper',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 150,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 150,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 150,
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
                          'variable' => 'suffix',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'mb_strtoupper',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'substr',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 151,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 151,
                                'char' => 50,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'encoding',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 151,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 151,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 151,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 151,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 152,
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
                          'variable' => 'suffix',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'substr',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 153,
                              'char' => 37,
                            ),
                            'name' => 'upper',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 153,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 153,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 154,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 155,
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
                      'variable' => 'suffix',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'substr',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 156,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 156,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 157,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 159,
              'char' => 10,
            ),
            3 => 
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
                      'value' => 'mb_strtolower',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 159,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 159,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 159,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'mb_strtolower',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'mb_substr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'text',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 160,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 160,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 160,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 160,
                                'char' => 51,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 160,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 160,
                                'char' => 54,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 160,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 160,
                          'char' => 55,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'encoding',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 160,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 160,
                          'char' => 65,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 160,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'suffix',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 160,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 160,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 161,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strtolower',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'substr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'text',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 162,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 162,
                                'char' => 42,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 162,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 162,
                                'char' => 45,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 162,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 162,
                                'char' => 48,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 162,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 162,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 162,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'suffix',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 162,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 162,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 163,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 164,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Decapitalizes the first letter of the sring and then adds it with rest
     * of the string. Omit the upperRest parameter to keep the rest of the
     * string intact, or set it to true to convert to uppercase.
     *
     * @param string $string
     * @param bool   $upperRest
     * @param string $encoding
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 140,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 140,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 135,
          'last-line' => 179,
          'char' => 32,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'dirFromFile',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 180,
              'char' => 58,
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 182,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'start',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 182,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 184,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'pathinfo',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 184,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 184,
                        'char' => 34,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PATHINFO_FILENAME',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 184,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 184,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 184,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 184,
                  'char' => 54,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'start',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'substr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 185,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 185,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 185,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 185,
                        'char' => 35,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '-2',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 185,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 185,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 185,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 185,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 187,
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
                  'value' => 'start',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 187,
                  'char' => 19,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 187,
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
                      'variable' => 'start',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 188,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 188,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 188,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 188,
                            'char' => 39,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 188,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 188,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 188,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 188,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 189,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 191,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
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
                        'value' => '/',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 191,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 191,
                      'char' => 25,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'str_split',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'start',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 191,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 191,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '2',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 191,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 191,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 191,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 191,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 191,
                  'char' => 48,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '/',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 191,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 191,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 192,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Accepts a file name (without extension) and returns a calculated
     * directory structure with the filename in the end
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::dirFromFile("file1234.jpg"); // fi/le/12/
     * ```
     *
     * @param string $file
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 181,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 181,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 180,
          'last-line' => 207,
          'char' => 32,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'dirSeparator',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'directory',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 208,
              'char' => 64,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'rtrim',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'directory',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 210,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 210,
                      'char' => 31,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'constant',
                        'value' => 'DIRECTORY_SEPARATOR',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 210,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 210,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 210,
                  'char' => 54,
                ),
                'right' => 
                array (
                  'type' => 'constant',
                  'value' => 'DIRECTORY_SEPARATOR',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 210,
                  'char' => 75,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 210,
                'char' => 75,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 211,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Accepts a directory name and ensures that it ends with
     * DIRECTORY_SEPARATOR
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::dirSeparator("/home/phalcon"); // /home/phalcon/
     * ```
     *
     * @param string $directory
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 209,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 209,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 208,
          'last-line' => 242,
          'char' => 32,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'dynamic',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 244,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'leftDelimiter',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '{',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 245,
                'char' => 34,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 245,
              'char' => 34,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'rightDelimiter',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '}',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 246,
                'char' => 35,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 246,
              'char' => 35,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'separator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '|',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 248,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 248,
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
                  'variable' => 'ldS',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 250,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'rdS',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 250,
                  'char' => 21,
                ),
                2 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 250,
                  'char' => 30,
                ),
                3 => 
                array (
                  'variable' => 'match',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 250,
                  'char' => 37,
                ),
                4 => 
                array (
                  'variable' => 'words',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 250,
                  'char' => 44,
                ),
                5 => 
                array (
                  'variable' => 'word',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 250,
                  'char' => 50,
                ),
                6 => 
                array (
                  'variable' => 'sub',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 250,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 251,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 251,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 253,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'substr_count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 253,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 253,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'leftDelimiter',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 253,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 253,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 253,
                    'char' => 57,
                  ),
                  'right' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'substr_count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 253,
                          'char' => 76,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 253,
                        'char' => 76,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'rightDelimiter',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 253,
                          'char' => 92,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 253,
                        'char' => 92,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 253,
                    'char' => 94,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 253,
                  'char' => 94,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 253,
                'char' => 94,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
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
                              'value' => 'Syntax error in string \\"',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 255,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 255,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 255,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\"',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 256,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 256,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 256,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 256,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 257,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 259,
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
                  'variable' => 'ldS',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_quote',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'leftDelimiter',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 259,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 259,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 259,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 259,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'rdS',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_quote',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'rightDelimiter',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 260,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 260,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 260,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 260,
                  'char' => 45,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'pattern',
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
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 261,
                                  'char' => 25,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'ldS',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 261,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 261,
                                'char' => 31,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '([^',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 261,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 261,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ldS',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 261,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 261,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'rdS',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 261,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 261,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ']+)',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 261,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 261,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'rdS',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 261,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 261,
                      'char' => 61,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '/',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 261,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 261,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 261,
                  'char' => 64,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'matches',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 262,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 262,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 264,
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
                  'type' => 'fcall',
                  'name' => 'preg_match_all',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pattern',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 264,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 264,
                      'char' => 35,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'text',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 264,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 264,
                      'char' => 41,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'matches',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 264,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 264,
                      'char' => 50,
                    ),
                    3 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'int',
                        'value' => '2',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 264,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 264,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 264,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 264,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'text',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 265,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 266,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 268,
              'char' => 10,
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
                    'value' => 'matches',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 268,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 268,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 268,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 268,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'matches',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 269,
                    'char' => 34,
                  ),
                  'value' => 'match',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'or',
                        'left' => 
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
                                'value' => 'match',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 270,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 270,
                                'char' => 34,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 270,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 270,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 270,
                          'char' => 37,
                        ),
                        'right' => 
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
                                'value' => 'match',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 270,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 270,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 270,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 270,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 270,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 270,
                        'char' => 55,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 272,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 274,
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
                          'variable' => 'words',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'explode',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'separator',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 274,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 274,
                                'char' => 46,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'match',
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 274,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 274,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 274,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 274,
                                'char' => 56,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 274,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 274,
                          'char' => 57,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'word',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'words',
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 275,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'array_rand',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'words',
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 275,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 275,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 275,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 275,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 275,
                          'char' => 52,
                        ),
                        2 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'sub',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'preg_quote',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'match',
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 276,
                                    'char' => 43,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 276,
                                    'char' => 45,
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 276,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 276,
                                'char' => 46,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'separator',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 276,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 276,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 276,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 276,
                          'char' => 58,
                        ),
                        3 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'text',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'preg_replace',
                            'call-type' => 1,
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
                                      'value' => '/',
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 277,
                                      'char' => 43,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sub',
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 277,
                                      'char' => 49,
                                    ),
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 277,
                                    'char' => 49,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '/',
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 277,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 277,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 277,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'word',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 277,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 277,
                                'char' => 58,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'text',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 277,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 277,
                                'char' => 64,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 277,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 277,
                                'char' => 67,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 277,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 277,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 278,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 279,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 281,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'text',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 281,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 282,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates random text in accordance with the template
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * // Hi my name is a Bob
     * echo Str::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hi my name is a Jon
     * echo Str::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hello my name is a Bob
     * echo Str::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hello my name is a Zyxep
     * echo Str::dynamic(
     *     "[Hi/Hello], my name is a [Zyxep/Mark]!",
     *     "[", "]",
     *     "/"
     * );
     * ```
     *
     * @param string $text
     * @param string $leftDelimiter
     * @param string $rightDelimiter
     * @param string $separator
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 249,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 249,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 243,
          'last-line' => 300,
          'char' => 32,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'endsWith',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 301,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'end',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 301,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ignoreCase',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 301,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 301,
              'char' => 90,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'ends_with',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 303,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 303,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'end',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 303,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 303,
                    'char' => 35,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ignoreCase',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 303,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 303,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 303,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 304,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a string ends with a given string
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::endsWith("Hello", "llo");          // true
     * echo Str::endsWith("Hello", "LLO", false);   // false
     * echo Str::endsWith("Hello", "LLO");          // true
     * ```
     *
     * @param string $text
     * @param string $end
     * @param bool   $ignoreCase
     *
     * @return bool
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 302,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 302,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 301,
          'last-line' => 315,
          'char' => 32,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'firstBetween',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 317,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'start',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 318,
              'char' => 22,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'end',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 320,
              'char' => 5,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'value' => 'mb_strstr',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 322,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 322,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 322,
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
                      'variable' => 'text',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'mb_strstr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'mb_strstr',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'text',
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 323,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 323,
                                    'char' => 57,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'start',
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 323,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 323,
                                    'char' => 64,
                                  ),
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 323,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 323,
                              'char' => 65,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'end',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 323,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 323,
                              'char' => 70,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 323,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 323,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 323,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 323,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 323,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 324,
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
                      'variable' => 'text',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strstr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'strstr',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'text',
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 325,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 325,
                                    'char' => 51,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'start',
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 325,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Helper/Str.zep',
                                    'line' => 325,
                                    'char' => 58,
                                  ),
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 325,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 325,
                              'char' => 59,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'end',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 325,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 325,
                              'char' => 64,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 325,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 325,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 325,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 325,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 325,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 326,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 328,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'trim',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 329,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 329,
                    'char' => 17,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'start',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 330,
                        'char' => 19,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'end',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 331,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 331,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 331,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 331,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 332,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the first string there is between the strings from the
     * parameter start and end.
     *
     * @param string $text
     * @param string $start
     * @param string $end
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 321,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 321,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 316,
          'last-line' => 347,
          'char' => 32,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'humanize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 348,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'preg_replace',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '#[_-]+#',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 350,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 350,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => ' ',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 350,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 350,
                    'char' => 39,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'trim',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'text',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 350,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 350,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 350,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 350,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 350,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 351,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Makes an underscored or dashed phrase human-readable
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::humanize("start-a-horse"); // "start a horse"
     * echo Str::humanize("five_cats");     // "five cats"
     * ```
     *
     * @param string $text
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 349,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 349,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 348,
          'last-line' => 360,
          'char' => 32,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'includes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'needle',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 361,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'haystack',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 361,
              'char' => 75,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'value' => 'mb_strpos',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 363,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 363,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 363,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'mb_strpos',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'haystack',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 364,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 364,
                          'char' => 45,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'needle',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 364,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 364,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 364,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 364,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 365,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strpos',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'haystack',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 366,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 366,
                          'char' => 42,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'needle',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 366,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 366,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 366,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 366,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 367,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 368,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Lets you determine whether or not a string includes another string.
     *
     * @param string $needle
     * @param string $haystack
     *
     * @return bool
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 362,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 362,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 361,
          'last-line' => 385,
          'char' => 32,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'increment',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 386,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'separator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '_',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 386,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 386,
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
                  'variable' => 'parts',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 388,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'number',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 388,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
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
                  'variable' => 'parts',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'explode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'separator',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 390,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 390,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 390,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 390,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 390,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 390,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 392,
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
                  'value' => 'number',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 392,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parts',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 392,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 392,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 392,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 392,
                'char' => 35,
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
                      'assign-type' => 'incr',
                      'variable' => 'number',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 393,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 394,
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
                      'variable' => 'number',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 395,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 395,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 396,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 398,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parts',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 398,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 398,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 398,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'separator',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 398,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 398,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'number',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 398,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 398,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 399,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a number to a string or increment that number if it already is
     * defined
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::increment("a");    // "a_1"
     * echo Str::increment("a_1");  // "a_2"
     * ```
     *
     * @param string $text
     * @param string $separator
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 387,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 387,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 386,
          'last-line' => 409,
          'char' => 32,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'isAnagram',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'first',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 410,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'second',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 410,
              'char' => 73,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'count_chars',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'first',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 412,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 412,
                      'char' => 33,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 412,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 412,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 412,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'count_chars',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'second',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 412,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 412,
                      'char' => 60,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 412,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 412,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 412,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 412,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 413,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Compare two strings and returns true if both strings are anagram,
     * false otherwise.
     *
     * @param string $first
     * @param string $second
     *
     * @return bool
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 411,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 411,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 410,
          'last-line' => 422,
          'char' => 32,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'isLower',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 423,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'encoding',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'UTF-8',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 423,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 423,
              'char' => 80,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'value' => 'mb_strtolower',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 425,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 425,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 425,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 426,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'mb_strtolower',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'text',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 426,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 426,
                          'char' => 47,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'encoding',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 426,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 426,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 426,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 426,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 427,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 428,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'text',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 428,
                        'char' => 34,
                      ),
                      'name' => 'lower',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 428,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 428,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 429,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 430,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true if the given string is lower case, false otherwise.
     *
     * @param string $text
     * @param string $encoding
     *
     * @return bool
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 424,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 424,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 423,
          'last-line' => 438,
          'char' => 32,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'isPalindrome',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 439,
              'char' => 59,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'strrev',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'text',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 441,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 441,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 441,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'text',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 441,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 441,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 442,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true if the given string is a palindrome, false otherwise.
     *
     * @param string $text
     *
     * @return bool
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 440,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 440,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 439,
          'last-line' => 451,
          'char' => 32,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'isUpper',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 452,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'encoding',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'UTF-8',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 452,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 452,
              'char' => 80,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'value' => 'mb_strtoupper',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 454,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 454,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 454,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 455,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'mb_strtoupper',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'text',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 455,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 455,
                          'char' => 47,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'encoding',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 455,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 455,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 455,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 455,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 456,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 457,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'text',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 457,
                        'char' => 34,
                      ),
                      'name' => 'upper',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 457,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 457,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 458,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 459,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true if the given string is upper case, false otherwise.
     *
     * @param string text
     * @param string encoding
     *
     * @return bool
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 453,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 453,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 452,
          'last-line' => 473,
          'char' => 32,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'lower',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 474,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'encoding',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'UTF-8',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 474,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 474,
              'char' => 78,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'value' => 'mb_strtolower',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 480,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 480,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 480,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_strtolower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 481,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 481,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'encoding',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 481,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 481,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 481,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 482,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 484,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'text',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 484,
                  'char' => 21,
                ),
                'name' => 'lower',
                'call-type' => 1,
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 484,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 485,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Lowercases a string, this function makes use of the mbstring extension if
     * available
     *
     * ```php
     * echo Phalcon\\Helper\\Str::lower("HELLO"); // hello
     * ```
     *
     * @param string $text
     * @param string $encoding
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 475,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 475,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 474,
          'last-line' => 501,
          'char' => 32,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'random',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 502,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 502,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'length',
              'const' => 0,
              'data-type' => 'long',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '8',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 502,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 502,
              'char' => 70,
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
                  'variable' => 'pool',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 504,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 505,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'end',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 505,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 506,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'text',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 506,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 506,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 508,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'type',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 508,
                'char' => 21,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Str',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 510,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'RANDOM_ALPHA',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 510,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 510,
                    'char' => 35,
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
                          'variable' => 'pool',
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
                                  'type' => 'fcall',
                                  'name' => 'range',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'a',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 511,
                                        'char' => 47,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 511,
                                      'char' => 47,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'z',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 511,
                                        'char' => 50,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 511,
                                      'char' => 50,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 511,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 511,
                                'char' => 51,
                              ),
                              1 => 
                              array (
                                'parameter' => 
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
                                        'type' => 'string',
                                        'value' => 'A',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 511,
                                        'char' => 60,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 511,
                                      'char' => 60,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'Z',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 511,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 511,
                                      'char' => 63,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 511,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 511,
                                'char' => 64,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 511,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 511,
                          'char' => 65,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 512,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 514,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 514,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Str',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 514,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'RANDOM_HEXDEC',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 514,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 514,
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
                          'variable' => 'pool',
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
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 515,
                                        'char' => 47,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 515,
                                      'char' => 47,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '9',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 515,
                                        'char' => 50,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 515,
                                      'char' => 50,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 515,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 515,
                                'char' => 51,
                              ),
                              1 => 
                              array (
                                'parameter' => 
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
                                        'type' => 'string',
                                        'value' => 'a',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 515,
                                        'char' => 60,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 515,
                                      'char' => 60,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'f',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 515,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 515,
                                      'char' => 63,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 515,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 515,
                                'char' => 64,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 515,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 515,
                          'char' => 65,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 516,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 518,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 518,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Str',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 518,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'RANDOM_NUMERIC',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 518,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 518,
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
                          'variable' => 'pool',
                          'expr' => 
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
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 519,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 519,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '9',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 519,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 519,
                                'char' => 38,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 519,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 519,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 520,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 522,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 522,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Str',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 522,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'RANDOM_NOZERO',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 522,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 522,
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
                          'variable' => 'pool',
                          'expr' => 
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
                                  'value' => '1',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 523,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 523,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '9',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 523,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 523,
                                'char' => 38,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 523,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 523,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 524,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 526,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 526,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Str',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 526,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'RANDOM_DISTINCT',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 526,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 526,
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
                          'variable' => 'pool',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_split',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '2345679ACDEFHJKLMNPRSTUVWXYZ',
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 527,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 527,
                                'char' => 66,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 527,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 527,
                          'char' => 67,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 528,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 530,
                      'char' => 19,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 530,
                  'char' => 19,
                ),
                5 => 
                array (
                  'type' => 'default',
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
                          'variable' => 'pool',
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
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 533,
                                        'char' => 28,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 533,
                                      'char' => 28,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '9',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 533,
                                        'char' => 31,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 533,
                                      'char' => 31,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 533,
                                  'char' => 32,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 533,
                                'char' => 32,
                              ),
                              1 => 
                              array (
                                'parameter' => 
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
                                        'type' => 'string',
                                        'value' => 'a',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 534,
                                        'char' => 28,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 534,
                                      'char' => 28,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'z',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 534,
                                        'char' => 31,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 534,
                                      'char' => 31,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 534,
                                  'char' => 32,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 534,
                                'char' => 32,
                              ),
                              2 => 
                              array (
                                'parameter' => 
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
                                        'type' => 'string',
                                        'value' => 'A',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 535,
                                        'char' => 28,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 535,
                                      'char' => 28,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'Z',
                                        'file' => '/app/phalcon/Helper/Str.zep',
                                        'line' => 535,
                                        'char' => 31,
                                      ),
                                      'file' => '/app/phalcon/Helper/Str.zep',
                                      'line' => 535,
                                      'char' => 31,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Str.zep',
                                  'line' => 536,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 536,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 536,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 536,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 538,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 539,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 539,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 541,
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
                  'variable' => 'end',
                  'expr' => 
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
                            'value' => 'pool',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 541,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 541,
                          'char' => 29,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 541,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 541,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 541,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 541,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 543,
              'char' => 13,
            ),
            5 => 
            array (
              'type' => 'while',
              'expr' => 
              array (
                'type' => 'less',
                'left' => 
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
                        'value' => 'text',
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 543,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 543,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 543,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'length',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 543,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 543,
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
                      'variable' => 'text',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pool',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 544,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'mt_rand',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 544,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 544,
                              'char' => 38,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'end',
                                'file' => '/app/phalcon/Helper/Str.zep',
                                'line' => 544,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Helper/Str.zep',
                              'line' => 544,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 544,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 544,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 544,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 545,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 547,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'text',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 547,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 548,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random string based on the given type. Type is one of the
     * RANDOM_* constants
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::random(Str::RANDOM_ALNUM); // "aloiwkqz"
     * ```
     *
     * @param int $type
     * @param int $length
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 503,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 503,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 502,
          'last-line' => 564,
          'char' => 32,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'reduceSlashes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 565,
              'char' => 60,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'preg_replace',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '#(?<!:)//+#',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 567,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 567,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '/',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 567,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 567,
                    'char' => 43,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 567,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 567,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 567,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 568,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reduces multiple slashes in a string to single slashes
     *
     * ```php
     * // foo/bar/baz
     * echo Phalcon\\Helper\\Str::reduceSlashes("foo//bar/baz");
     *
     * // http://foo.bar/baz/buz
     * echo Phalcon\\Helper\\Str::reduceSlashes("http://foo.bar///baz/buz");
     * ```
     *
     * @param string $text
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 566,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 566,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 565,
          'last-line' => 586,
          'char' => 32,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'startsWith',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 587,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'start',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 587,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ignoreCase',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 587,
                'char' => 96,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 587,
              'char' => 96,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'starts_with',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 589,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 589,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'start',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 589,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 589,
                    'char' => 39,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ignoreCase',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 589,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 589,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 589,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 590,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a string starts with a given string
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::startsWith("Hello", "He");         // true
     * echo Str::startsWith("Hello", "he", false);  // false
     * echo Str::startsWith("Hello", "he");         // true
     * ```
     *
     * @param string $text
     * @param string $start
     * @param bool   $ignoreCase
     *
     * @return bool
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 588,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 588,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 587,
          'last-line' => 606,
          'char' => 32,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'uncamelize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 607,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'delimiter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 607,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 607,
              'char' => 79,
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
                  'value' => 'text',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 609,
                  'char' => 21,
                ),
                'name' => 'uncamelize',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 609,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 609,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 609,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 610,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Uncamelize strings which are camelized
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::uncamelize("CocoBongo");       // coco_bongo
     * echo Str::uncamelize("CocoBongo", "-");  // coco-bongo
     * ```
     *
     * @param string $text
     * @param mixed  $delimiter
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 608,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 608,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 607,
          'last-line' => 625,
          'char' => 32,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'underscore',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 626,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'preg_replace',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '#\\s+#',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 628,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 628,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '_',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 628,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 628,
                    'char' => 37,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'trim',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'text',
                            'file' => '/app/phalcon/Helper/Str.zep',
                            'line' => 628,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 628,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 628,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 628,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 628,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 629,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Makes a phrase underscored instead of spaced
     *
     * ```php
     * use Phalcon\\Helper\\Str;
     *
     * echo Str::underscore("look behind");     // "look_behind"
     * echo Str::underscore("Awesome Phalcon"); // "Awesome_Phalcon"
     * ```
     *
     * @param string $text
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 627,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 627,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 626,
          'last-line' => 643,
          'char' => 32,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'upper',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 644,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'encoding',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'UTF-8',
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 644,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 644,
              'char' => 78,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'value' => 'mb_strtoupper',
                      'file' => '/app/phalcon/Helper/Str.zep',
                      'line' => 650,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 650,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 650,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_strtoupper',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 651,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 651,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'encoding',
                          'file' => '/app/phalcon/Helper/Str.zep',
                          'line' => 651,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Helper/Str.zep',
                        'line' => 651,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Str.zep',
                    'line' => 651,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 652,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 654,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'text',
                  'file' => '/app/phalcon/Helper/Str.zep',
                  'line' => 654,
                  'char' => 21,
                ),
                'name' => 'upper',
                'call-type' => 1,
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 654,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Helper/Str.zep',
              'line' => 655,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Uppercases a string, this function makes use of the mbstring extension if
     * available
     *
     * ```php
     * echo Phalcon\\Helper\\Str::upper("hello"); // HELLO
     * ```
     *
     * @param string $text
     * @param string $encoding
     *
     * @return string
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
                'file' => '/app/phalcon/Helper/Str.zep',
                'line' => 645,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 645,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 644,
          'last-line' => 656,
          'char' => 32,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'RANDOM_ALNUM',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 22,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 23,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'RANDOM_ALPHA',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 23,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 24,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'RANDOM_DISTINCT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 24,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 25,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'RANDOM_HEXDEC',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 25,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 26,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'RANDOM_NOZERO',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 26,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 27,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'RANDOM_NUMERIC',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Helper/Str.zep',
            'line' => 27,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Helper/Str.zep',
          'line' => 44,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Helper/Str.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Helper/Str.zep',
    'line' => 20,
    'char' => 5,
  ),
);