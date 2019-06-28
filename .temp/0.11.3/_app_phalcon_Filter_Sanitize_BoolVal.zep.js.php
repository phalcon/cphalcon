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
    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\BoolVal
 *
 * Sanitizes a value to boolean
 *',
    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'BoolVal',
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
          'name' => '__invoke',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'input',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
              'line' => 23,
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
                  'variable' => 'falseArray',
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 25,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'trueArray',
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 25,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
              'line' => 27,
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
                  'variable' => 'trueArray',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'true',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 27,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 27,
                        'char' => 31,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'on',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 27,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 27,
                        'char' => 35,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'yes',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 27,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 27,
                        'char' => 40,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'y',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 27,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 27,
                        'char' => 43,
                      ),
                      4 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => '1',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 27,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 27,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                    'line' => 27,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 27,
                  'char' => 47,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'falseArray',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'false',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 28,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 28,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'off',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 28,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 28,
                        'char' => 37,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'no',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 28,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 28,
                        'char' => 41,
                      ),
                      3 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'n',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 28,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 28,
                        'char' => 44,
                      ),
                      4 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => '0',
                          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                          'line' => 28,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 28,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                    'line' => 28,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 28,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
              'line' => 30,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 30,
                  'char' => 19,
                ),
                'right' => 
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
                        'value' => 'input',
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 30,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                      'line' => 30,
                      'char' => 35,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'trueArray',
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 30,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                      'line' => 30,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 30,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                'line' => 30,
                'char' => 48,
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
                    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                    'line' => 31,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 32,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
              'line' => 34,
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
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 34,
                  'char' => 19,
                ),
                'right' => 
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
                        'value' => 'input',
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 34,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                      'line' => 34,
                      'char' => 35,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'falseArray',
                        'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                        'line' => 34,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                      'line' => 34,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 34,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                'line' => 34,
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
                    'value' => 'false',
                    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                    'line' => 35,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 36,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
              'line' => 38,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'bool',
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'input',
                  'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                  'line' => 38,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
                'line' => 38,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
          'line' => 23,
          'last-line' => 40,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/BoolVal.zep',
    'line' => 18,
    'char' => 5,
  ),
);