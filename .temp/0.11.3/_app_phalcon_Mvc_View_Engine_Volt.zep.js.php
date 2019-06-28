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
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\View\\Engine',
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
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
        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
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
        'name' => 'Phalcon\\Mvc\\View\\Engine\\AbstractEngine',
        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
        'line' => 14,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
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
        'name' => 'Phalcon\\Mvc\\View\\Engine\\Volt\\Compiler',
        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
        'line' => 15,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
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
        'name' => 'Phalcon\\Mvc\\View\\Exception',
        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
        'line' => 16,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
    'line' => 20,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Designer friendly and fast template engine for PHP written in Zephir/C
 *',
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
    'line' => 21,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Volt',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractEngine',
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
          'name' => 'compiler',
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 24,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'macros',
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 25,
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
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 29,
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
          'name' => 'callMacro',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 30,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 30,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 30,
              'char' => 65,
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
                  'variable' => 'macro',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 32,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 34,
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
                      'value' => 'macro',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 34,
                      'char' => 54,
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
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 34,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'macros',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 34,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 34,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 34,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 34,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 34,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 34,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 34,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Macro \'',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 35,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 35,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 35,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\' does not exist',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 35,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 35,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 35,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 35,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 36,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 38,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
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
                      'value' => 'macro',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 38,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 38,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'arguments',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 38,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 38,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 38,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a macro is defined and calls it
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
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 31,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
            'line' => 31,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 30,
          'last-line' => 43,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'convertEncoding',
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
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 44,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'from',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 44,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'to',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 44,
              'char' => 74,
            ),
          ),
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'from',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 49,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'latin1',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 49,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 49,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'to',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 49,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'utf8',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 49,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 49,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 49,
                'char' => 41,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'utf8_encode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 50,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 50,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 50,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 51,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 56,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'to',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 56,
                    'char' => 16,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'latin1',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 56,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 56,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'from',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 56,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'utf8',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 56,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 56,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 56,
                'char' => 41,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'utf8_decode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 57,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 57,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 57,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 58,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 63,
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
                      'value' => 'mb_convert_encoding',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 63,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 63,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 63,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_convert_encoding',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 64,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 64,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'from',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 64,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 64,
                        'char' => 50,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'to',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 64,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 64,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 64,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 65,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 70,
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
                      'value' => 'iconv',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 70,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 70,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 70,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'iconv',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'from',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 71,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 71,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'to',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 71,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 71,
                        'char' => 34,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 71,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 71,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 71,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 72,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 77,
              'char' => 13,
            ),
            4 => 
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
                      'value' => 'Any of \'mbstring\' or \'iconv\' is required to perform the charset conversion',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 79,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 79,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 79,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Performs a string conversion
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
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 45,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
            'line' => 45,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 44,
          'last-line' => 84,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCompiler',
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
                  'variable' => 'compiler',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 87,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 87,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 87,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 89,
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
                  'variable' => 'compiler',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 89,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'compiler',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 89,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 89,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 89,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 91,
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
                    'value' => 'compiler',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 91,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 91,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 91,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 91,
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
                      'variable' => 'compiler',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Compiler',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                'line' => 92,
                                'char' => 46,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'view',
                                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                'line' => 92,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 92,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 92,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 92,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 92,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 97,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'DiInterface',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 97,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 97,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 97,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 97,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 97,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 97,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 99,
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
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 99,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 99,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 99,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 99,
                    'char' => 43,
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
                          'value' => 'compiler',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 100,
                          'char' => 26,
                        ),
                        'name' => 'setDi',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 100,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 100,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 100,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 101,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 106,
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
                      'variable' => 'options',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 106,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 106,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 106,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 106,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 108,
                  'char' => 14,
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
                        'value' => 'options',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 108,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 108,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 108,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 108,
                    'char' => 40,
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
                          'value' => 'compiler',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 109,
                          'char' => 26,
                        ),
                        'name' => 'setOptions',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 109,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 109,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 109,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 110,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 112,
                  'char' => 15,
                ),
                5 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'compiler',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'compiler',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 112,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 112,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 113,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 115,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'compiler',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 115,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 116,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the Volt\'s compiler
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
                  'value' => 'Compiler',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 86,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 86,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 85,
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
          'name' => 'getOptions',
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
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 123,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'options',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 123,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 123,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 124,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return Volt\'s options
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
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 121,
          'last-line' => 128,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isIncluded',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'needle',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 129,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'haystack',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 129,
              'char' => 56,
            ),
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
                    'value' => 'haystack',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 131,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 131,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 131,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 131,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
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
                          'value' => 'needle',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 132,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 132,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'haystack',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 132,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 132,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 132,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 133,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 135,
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
                    'value' => 'haystack',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 135,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 135,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 135,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 135,
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
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 136,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 136,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 136,
                    'char' => 43,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
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
                                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                'line' => 137,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 137,
                              'char' => 42,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'needle',
                                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                'line' => 137,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 137,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 137,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 137,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 137,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 138,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 140,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
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
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 140,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 140,
                          'char' => 35,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'needle',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 140,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 140,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 140,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 140,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 140,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 141,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 143,
              'char' => 13,
            ),
            2 => 
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
                      'value' => 'Invalid haystack',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 143,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 143,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 143,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 144,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if the needle is included in the haystack
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
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 130,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
            'line' => 130,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 129,
          'last-line' => 148,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'length',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 149,
              'char' => 36,
            ),
          ),
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'item',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 151,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 151,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 151,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 151,
                  'char' => 35,
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
                      'value' => 'item',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 151,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 151,
                    'char' => 50,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 151,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 151,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 151,
                'char' => 58,
              ),
              'statements' => 
              array (
                0 => 
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
                          'type' => 'variable',
                          'value' => 'item',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 152,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 152,
                        'char' => 30,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 152,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 153,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 155,
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
                      'value' => 'mb_strlen',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 155,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 155,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 155,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
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
                          'value' => 'item',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 156,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 156,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 156,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 157,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 159,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
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
                      'value' => 'item',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 159,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 159,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 159,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 160,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
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
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 150,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
            'line' => 150,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 149,
          'last-line' => 164,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'render',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'templatePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 165,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 165,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'mustClean',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 165,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 165,
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
                  'variable' => 'compiler',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 167,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'compiledTemplatePath',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 167,
                  'char' => 43,
                ),
                2 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 167,
                  'char' => 58,
                ),
                3 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 167,
                  'char' => 63,
                ),
                4 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 167,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 169,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'mustClean',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 169,
                'char' => 22,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'ob_clean',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 170,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 171,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 176,
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
                  'variable' => 'compiler',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 176,
                      'char' => 34,
                    ),
                    'name' => 'getCompiler',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 176,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 176,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 177,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 177,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 177,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 177,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 179,
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 179,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 179,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 179,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 179,
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 180,
                        'char' => 30,
                      ),
                      'name' => 'fire',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'view:beforeCompile',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 180,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 180,
                          'char' => 54,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 180,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 180,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 180,
                      'char' => 64,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 180,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 180,
                    'char' => 72,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 181,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 182,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 183,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 185,
              'char' => 16,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'compiler',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 185,
                  'char' => 18,
                ),
                'name' => 'compile',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'templatePath',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 185,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 185,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 185,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 187,
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
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 187,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 187,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 187,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 187,
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 188,
                        'char' => 30,
                      ),
                      'name' => 'fire',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'view:afterCompile',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 188,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 188,
                          'char' => 53,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 188,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 188,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 188,
                      'char' => 63,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 188,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 188,
                    'char' => 71,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 189,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 190,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 191,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 193,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'compiledTemplatePath',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'compiler',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 193,
                      'char' => 45,
                    ),
                    'name' => 'getCompiledTemplatePath',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 193,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 193,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 198,
              'char' => 10,
            ),
            7 => 
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
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 198,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 198,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 198,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 198,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 199,
                    'char' => 38,
                  ),
                  'key' => 'key',
                  'value' => 'value',
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
                          'assign-type' => 'dynamic-variable',
                          'operator' => 'assign',
                          'variable' => 'key',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 200,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 200,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 201,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 202,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 204,
              'char' => 15,
            ),
            8 => 
            array (
              'type' => 'require',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'compiledTemplatePath',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 204,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 206,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'mustClean',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 206,
                'char' => 22,
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 207,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'view',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 207,
                        'char' => 24,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 207,
                      'char' => 24,
                    ),
                    'name' => 'setContent',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'ob_get_contents',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 207,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 207,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 207,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 208,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 209,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders a view using the template engine
     *',
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 165,
          'last-line' => 213,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 214,
              'char' => 46,
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
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 216,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 216,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 217,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set Volt\'s options
     *',
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 214,
          'last-line' => 221,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'slice',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 222,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'start',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 222,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 222,
              'char' => 51,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'end',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 222,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 222,
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
                  'variable' => 'length',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 224,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 225,
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
                  'variable' => 'slice',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 225,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 226,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'position',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 226,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 231,
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 231,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 231,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 231,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 231,
                'char' => 35,
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
                      'value' => 'end',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 232,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 232,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 232,
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
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                    'line' => 233,
                                    'char' => 38,
                                  ),
                                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                  'line' => 233,
                                  'char' => 38,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 233,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 233,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 233,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 233,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 234,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 236,
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
                      'variable' => 'position',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 236,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 236,
                      'char' => 29,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'slice',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 237,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 237,
                      'char' => 27,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 239,
                  'char' => 17,
                ),
                2 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 239,
                      'char' => 19,
                    ),
                    'name' => 'rewind',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 239,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 241,
                  'char' => 17,
                ),
                3 => 
                array (
                  'type' => 'while',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 241,
                      'char' => 25,
                    ),
                    'name' => 'valid',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 241,
                    'char' => 34,
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
                          'type' => 'greater-equal',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'position',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 242,
                            'char' => 29,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'start',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 242,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 242,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'less-equal',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'position',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 242,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'end',
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 242,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 242,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 242,
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
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'slice',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                  'line' => 243,
                                  'char' => 41,
                                ),
                                'name' => 'current',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                                'line' => 243,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 243,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 244,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 246,
                      'char' => 21,
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
                          'value' => 'value',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 246,
                          'char' => 23,
                        ),
                        'name' => 'next',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 246,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 248,
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
                          'variable' => 'position',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 248,
                          'char' => 31,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 249,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 251,
                  'char' => 18,
                ),
                4 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'slice',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 251,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 252,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 257,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'end',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 257,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 257,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 257,
                'char' => 25,
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
                        'type' => 'add',
                        'left' => 
                        array (
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'sub',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'end',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 258,
                              'char' => 31,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'start',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 258,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 258,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 258,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 258,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 258,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 258,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 259,
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
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 260,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 260,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 261,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 266,
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 266,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 266,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 266,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 266,
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
                    'name' => 'array_slice',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 267,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 267,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'start',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 267,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 267,
                        'char' => 44,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 267,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 267,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 267,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 268,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 273,
              'char' => 10,
            ),
            6 => 
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
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 273,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 273,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 273,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'length',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 274,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 274,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 274,
                    'char' => 32,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'value' => 'value',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 275,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 275,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'start',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 275,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 275,
                            'char' => 46,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'length',
                              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                              'line' => 275,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                            'line' => 275,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 275,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 276,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 278,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
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
                          'value' => 'value',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 278,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 278,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'start',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 278,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 278,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 278,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 279,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 284,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'length',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 284,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 284,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 284,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
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
                          'value' => 'value',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 285,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 285,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'start',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 285,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 285,
                        'char' => 39,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                          'line' => 285,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                        'line' => 285,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 285,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                  'line' => 286,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 288,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
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
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 288,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 288,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'start',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 288,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 288,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 288,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 289,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Extracts a slice from a string/array/traversable object value
     *',
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 222,
          'last-line' => 293,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'sort',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 294,
              'char' => 37,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'asort',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                      'line' => 296,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                    'line' => 296,
                    'char' => 20,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 296,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 298,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 298,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
              'line' => 299,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sorts an array
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
                'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
                'line' => 295,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
            'line' => 295,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
          'line' => 294,
          'last-line' => 300,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Volt.zep',
    'line' => 21,
    'char' => 5,
  ),
);