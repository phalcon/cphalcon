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
    'file' => '/app/phalcon/Debug/Dump.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Debug',
    'file' => '/app/phalcon/Debug/Dump.zep',
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
        'file' => '/app/phalcon/Debug/Dump.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Debug/Dump.zep',
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
        'name' => 'Reflection',
        'file' => '/app/phalcon/Debug/Dump.zep',
        'line' => 14,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Debug/Dump.zep',
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
        'name' => 'ReflectionClass',
        'file' => '/app/phalcon/Debug/Dump.zep',
        'line' => 15,
        'char' => 20,
      ),
    ),
    'file' => '/app/phalcon/Debug/Dump.zep',
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
        'name' => 'ReflectionProperty',
        'file' => '/app/phalcon/Debug/Dump.zep',
        'line' => 16,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Debug/Dump.zep',
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
        'name' => 'stdClass',
        'file' => '/app/phalcon/Debug/Dump.zep',
        'line' => 17,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Debug/Dump.zep',
    'line' => 35,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Dumps information about a variable(s)
 *
 * ```php
 * $foo = 123;
 *
 * echo (new \\Phalcon\\Debug\\Dump())->variable($foo, "foo");
 * ```
 *
 * ```php
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \\Phalcon\\Debug\\Dump())->variables($foo, $bar, $baz);
 * ```
 *',
    'file' => '/app/phalcon/Debug/Dump.zep',
    'line' => 36,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Dump',
    'abstract' => 0,
    'final' => 0,
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
          'name' => 'detailed',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 41,
            'char' => 32,
          ),
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 41,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 41,
              'char' => 43,
            ),
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 45,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'methods',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 46,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 50,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'styles',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 51,
            'char' => 26,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 55,
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
              'name' => 'styles',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 56,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 56,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'detailed',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 56,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 56,
              'char' => 74,
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
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 58,
                  'char' => 14,
                ),
                'name' => 'setStyles',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'styles',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 58,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 58,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 58,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 60,
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
                  'property' => 'detailed',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'detailed',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 60,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 60,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Debug\\Dump constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 57,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 56,
          'last-line' => 66,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'all',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
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
                      'type' => 'array',
                      'left' => 
                      array (
                        0 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 71,
                            'char' => 21,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 71,
                          'char' => 21,
                        ),
                        1 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'string',
                            'value' => 'variables',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 73,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 73,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 73,
                      'char' => 14,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 73,
                    'char' => 14,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'func_get_args',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 75,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 75,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 75,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 76,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Alias of variables() method
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 68,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 68,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 67,
          'last-line' => 80,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'one',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'variable',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 81,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 81,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 81,
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
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 83,
                  'char' => 21,
                ),
                'name' => 'variable',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 83,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 83,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 83,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 83,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 83,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Alias of variable() method
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 82,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 82,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 81,
          'last-line' => 88,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setStyles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'styles',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 89,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 89,
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
                  'variable' => 'defaultStyles',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 91,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 93,
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
                  'variable' => 'defaultStyles',
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
                          'value' => 'pre',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 94,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'background-color:#f3f3f3; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 94,
                          'char' => 127,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 94,
                        'char' => 127,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'arr',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 95,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:red',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 95,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 95,
                        'char' => 30,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'bool',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 96,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:green',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 96,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 96,
                        'char' => 32,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'float',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 97,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:fuchsia',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 97,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 97,
                        'char' => 34,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'int',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 98,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:blue',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 98,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 98,
                        'char' => 31,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'null',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 99,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:black',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 99,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 99,
                        'char' => 32,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'num',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 100,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:navy',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 100,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 100,
                        'char' => 31,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'obj',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 101,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:purple',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 101,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 101,
                        'char' => 33,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'other',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 102,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:maroon',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 102,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 102,
                        'char' => 33,
                      ),
                      9 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'res',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 103,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:lime',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 103,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 103,
                        'char' => 31,
                      ),
                      10 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'str',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 104,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'color:teal',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 105,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 105,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 105,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 105,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 107,
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
                  'property' => 'styles',
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
                          'type' => 'variable',
                          'value' => 'defaultStyles',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 107,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 107,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'styles',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 107,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 107,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 107,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 107,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 109,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 109,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'styles',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 109,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 109,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 110,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set styles for vars type
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 89,
          'last-line' => 127,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toJson',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'variable',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 128,
              'char' => 40,
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
                'name' => 'json_encode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 131,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 131,
                    'char' => 21,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bitwise_or',
                      'left' => 
                      array (
                        'type' => 'bitwise_or',
                        'left' => 
                        array (
                          'type' => 'constant',
                          'value' => 'JSON_PRETTY_PRINT',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 132,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'JSON_UNESCAPED_SLASHES',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 132,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 132,
                        'char' => 56,
                      ),
                      'right' => 
                      array (
                        'type' => 'constant',
                        'value' => 'JSON_UNESCAPED_UNICODE',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 133,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 133,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 133,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 133,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 134,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an JSON string of information about a single variable.
     *
     * ```php
     * $foo = [
     *     "key" => "value",
     * ];
     *
     * echo (new \\Phalcon\\Debug\\Dump())->toJson($foo);
     *
     * $foo = new stdClass();
     * $foo->bar = "buz";
     *
     * echo (new \\Phalcon\\Debug\\Dump())->toJson($foo);
     * ```
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 129,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 129,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 128,
          'last-line' => 142,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'variable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'variable',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 143,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 143,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 143,
              'char' => 62,
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
                'name' => 'strtr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '<pre style=\':style\'>:output</pre>',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 146,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 146,
                    'char' => 46,
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
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => ':style',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 148,
                            'char' => 23,
                          ),
                          'value' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 148,
                              'char' => 31,
                            ),
                            'name' => 'getStyle',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'pre',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 148,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 148,
                                'char' => 44,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 148,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 148,
                          'char' => 45,
                        ),
                        1 => 
                        array (
                          'key' => 
                          array (
                            'type' => 'string',
                            'value' => ':output',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 149,
                            'char' => 24,
                          ),
                          'value' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 149,
                              'char' => 31,
                            ),
                            'name' => 'output',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'variable',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 149,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 149,
                                'char' => 47,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 149,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 149,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 150,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 150,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 151,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 151,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 151,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 152,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an HTML string of information about a single variable.
     *
     * ```php
     * echo (new \\Phalcon\\Debug\\Dump())->variable($foo, "foo");
     * ```
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 144,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 144,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 143,
          'last-line' => 165,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'variables',
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 168,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 168,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 169,
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
                  'variable' => 'output',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 169,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 171,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 171,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 171,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 173,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'func_get_args',
                'call-type' => 1,
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 173,
                'char' => 43,
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
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'output',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 174,
                          'char' => 31,
                        ),
                        'name' => 'one',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 175,
                              'char' => 22,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 175,
                            'char' => 22,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'var ',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 176,
                                'char' => 22,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'key',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 177,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 177,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 177,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 177,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 177,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 178,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 180,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 180,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 181,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an HTML string of debugging information about any number of
     * variables, each wrapped in a "pre" tag.
     *
     * ```php
     * $foo = "string";
     * $bar = ["key" => "value"];
     * $baz = new stdClass();
     *
     * echo (new \\Phalcon\\Debug\\Dump())->variables($foo, $bar, $baz);
     * ```
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 167,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 167,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 166,
          'last-line' => 185,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getStyle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 186,
              'char' => 45,
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
                  'variable' => 'style',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 188,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 190,
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
                    'value' => 'style',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 190,
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
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 190,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'styles',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 190,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 190,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 190,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 190,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 190,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 190,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'color:gray',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 191,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 192,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 194,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'style',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 194,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 195,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get style for type
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 187,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 187,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 186,
          'last-line' => 199,
          'char' => 22,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'output',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'variable',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 200,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 200,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 200,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'tab',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 200,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 200,
              'char' => 76,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 202,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 202,
                  'char' => 23,
                ),
                2 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 202,
                  'char' => 31,
                ),
                3 => 
                array (
                  'variable' => 'space',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 202,
                  'char' => 38,
                ),
                4 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 202,
                  'char' => 44,
                ),
                5 => 
                array (
                  'variable' => 'attr',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 202,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 204,
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
                  'variable' => 'space',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '  ',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 204,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 204,
                  'char' => 23,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 205,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 205,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 207,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'name',
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 207,
                'char' => 17,
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
                      'variable' => 'output',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 208,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' ',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 208,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 208,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 208,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 209,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 211,
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
                    'value' => 'variable',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 211,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 211,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 211,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 211,
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
                      'variable' => 'output',
                      'expr' => 
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
                              'type' => 'string',
                              'value' => '<b style =\':style\'>Array</b> (<span style =\':style\'>:count</span>) (\\n',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 213,
                              'char' => 87,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 213,
                            'char' => 87,
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
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ':style',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 215,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 215,
                                      'char' => 34,
                                    ),
                                    'name' => 'getStyle',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'arr',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 215,
                                          'char' => 47,
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 215,
                                        'char' => 47,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 215,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 215,
                                  'char' => 48,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ':count',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 216,
                                    'char' => 27,
                                  ),
                                  'value' => 
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
                                          'value' => 'variable',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 216,
                                          'char' => 43,
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 216,
                                        'char' => 43,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 217,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 217,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 218,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 218,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 218,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 218,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 220,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'variable',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 220,
                    'char' => 40,
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
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'str_repeat',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'space',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 221,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 221,
                                  'char' => 46,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'tab',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 221,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 221,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 221,
                              'char' => 53,
                            ),
                            'right' => 
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
                                    'type' => 'string',
                                    'value' => '[<span style=\':style\'>:key</span>] => ',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 221,
                                    'char' => 99,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 221,
                                  'char' => 99,
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
                                        'key' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ':style',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 221,
                                          'char' => 108,
                                        ),
                                        'value' => 
                                        array (
                                          'type' => 'mcall',
                                          'variable' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'this',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 221,
                                            'char' => 115,
                                          ),
                                          'name' => 'getStyle',
                                          'call-type' => 1,
                                          'parameters' => 
                                          array (
                                            0 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'arr',
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 221,
                                                'char' => 128,
                                              ),
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 221,
                                              'char' => 128,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 221,
                                          'char' => 129,
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 221,
                                        'char' => 129,
                                      ),
                                      1 => 
                                      array (
                                        'key' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ':key',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 221,
                                          'char' => 135,
                                        ),
                                        'value' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'key',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 221,
                                          'char' => 140,
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 221,
                                        'char' => 140,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 221,
                                    'char' => 141,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 221,
                                  'char' => 141,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 221,
                              'char' => 142,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 221,
                            'char' => 142,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 221,
                          'char' => 142,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 223,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'and',
                          'left' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'tab',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 223,
                                'char' => 25,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 223,
                                'char' => 30,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 223,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'not-equals',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'name',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 223,
                                'char' => 38,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 223,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 223,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 223,
                            'char' => 42,
                          ),
                          'right' => 
                          array (
                            'type' => 'not',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'is_int',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'key',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 223,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 223,
                                  'char' => 55,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 223,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 223,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 223,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'name',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 223,
                            'char' => 66,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 223,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 223,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 223,
                        'char' => 72,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 225,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 227,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 227,
                                'char' => 35,
                              ),
                              'name' => 'output',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 227,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 227,
                                  'char' => 48,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 227,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 227,
                                  'char' => 50,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'add',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'tab',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 227,
                                      'char' => 56,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 227,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 227,
                                    'char' => 59,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 227,
                                  'char' => 59,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 227,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\n',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 227,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 227,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 227,
                          'char' => 65,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 228,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 230,
                  'char' => 18,
                ),
                2 => 
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
                        'value' => 'output',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 230,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'str_repeat',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'space',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 230,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 230,
                            'char' => 45,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'sub',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'tab',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 230,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 230,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 230,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 230,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 230,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 230,
                      'char' => 56,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 230,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 230,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 231,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 233,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'variable',
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 233,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 233,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 233,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 233,
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
                      'operator' => 'concat-assign',
                      'variable' => 'output',
                      'expr' => 
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
                              'type' => 'string',
                              'value' => '<b style=\':style\'>Object</b> :class',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 235,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 235,
                            'char' => 52,
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
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ':style',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 237,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 237,
                                      'char' => 34,
                                    ),
                                    'name' => 'getStyle',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'obj',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 237,
                                          'char' => 47,
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 237,
                                        'char' => 47,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 237,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 237,
                                  'char' => 48,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ':class',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 238,
                                    'char' => 27,
                                  ),
                                  'value' => 
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
                                          'value' => 'variable',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 238,
                                          'char' => 47,
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 238,
                                        'char' => 47,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 239,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 239,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 240,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 240,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 240,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 240,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 242,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'get_parent_class',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'variable',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 242,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 242,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 242,
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
                          'variable' => 'output',
                          'expr' => 
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
                                  'type' => 'string',
                                  'value' => ' <b style=\':style\'>extends</b> :parent',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 244,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 244,
                                'char' => 59,
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
                                      'key' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ':style',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 246,
                                        'char' => 31,
                                      ),
                                      'value' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 246,
                                          'char' => 38,
                                        ),
                                        'name' => 'getStyle',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'obj',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 246,
                                              'char' => 51,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 246,
                                            'char' => 51,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 246,
                                        'char' => 52,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 246,
                                      'char' => 52,
                                    ),
                                    1 => 
                                    array (
                                      'key' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ':parent',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 247,
                                        'char' => 32,
                                      ),
                                      'value' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'get_parent_class',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'variable',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 247,
                                              'char' => 59,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 247,
                                            'char' => 59,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 248,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 248,
                                      'char' => 21,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 249,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 249,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 249,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 249,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 250,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 251,
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
                      'operator' => 'concat-assign',
                      'variable' => 'output',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => ' (\\n',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 251,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 251,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 253,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'instanceof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 253,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Di',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 253,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 253,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'str_repeat',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'space',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 255,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 255,
                                  'char' => 46,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'tab',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 255,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 255,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 255,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '[skipped]\\n',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 255,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 255,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 255,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 256,
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
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 256,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'detailed',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 256,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 256,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 256,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'instanceof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'variable',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 256,
                            'char' => 59,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'stdClass',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 256,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 256,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 256,
                        'char' => 70,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'get_object_vars',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'variable',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 258,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 258,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 258,
                            'char' => 61,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'output',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'str_repeat',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'space',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 259,
                                            'char' => 50,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 259,
                                          'char' => 50,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'tab',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 259,
                                            'char' => 55,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 259,
                                          'char' => 55,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 259,
                                      'char' => 57,
                                    ),
                                    'right' => 
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
                                            'type' => 'string',
                                            'value' => '-><span style=\':style\'>:key</span> (<span style=\':style\'>:type</span>) = ',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 259,
                                            'char' => 138,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 259,
                                          'char' => 138,
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
                                                'key' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ':style',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 259,
                                                  'char' => 147,
                                                ),
                                                'value' => 
                                                array (
                                                  'type' => 'mcall',
                                                  'variable' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'this',
                                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                                    'line' => 259,
                                                    'char' => 154,
                                                  ),
                                                  'name' => 'getStyle',
                                                  'call-type' => 1,
                                                  'parameters' => 
                                                  array (
                                                    0 => 
                                                    array (
                                                      'parameter' => 
                                                      array (
                                                        'type' => 'string',
                                                        'value' => 'obj',
                                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                                        'line' => 259,
                                                        'char' => 167,
                                                      ),
                                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                                      'line' => 259,
                                                      'char' => 167,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 259,
                                                  'char' => 168,
                                                ),
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 259,
                                                'char' => 168,
                                              ),
                                              1 => 
                                              array (
                                                'key' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ':key',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 259,
                                                  'char' => 174,
                                                ),
                                                'value' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'key',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 259,
                                                  'char' => 179,
                                                ),
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 259,
                                                'char' => 179,
                                              ),
                                              2 => 
                                              array (
                                                'key' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ':type',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 259,
                                                  'char' => 186,
                                                ),
                                                'value' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => 'public',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 259,
                                                  'char' => 194,
                                                ),
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 259,
                                                'char' => 194,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 259,
                                            'char' => 195,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 259,
                                          'char' => 195,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 259,
                                      'char' => 196,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 259,
                                    'char' => 196,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 259,
                                  'char' => 196,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 260,
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'output',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 260,
                                        'char' => 39,
                                      ),
                                      'name' => 'output',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'value',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 260,
                                            'char' => 52,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 260,
                                          'char' => 52,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 260,
                                            'char' => 54,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 260,
                                          'char' => 54,
                                        ),
                                        2 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'add',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'tab',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 260,
                                              'char' => 60,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '1',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 260,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 260,
                                            'char' => 63,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 260,
                                          'char' => 63,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 260,
                                      'char' => 65,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\n',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 260,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 260,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 260,
                                  'char' => 69,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 261,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 262,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 262,
                      'char' => 18,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'declare',
                      'data-type' => 'variable',
                      'variables' => 
                      array (
                        0 => 
                        array (
                          'variable' => 'reflect',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 264,
                          'char' => 28,
                        ),
                        1 => 
                        array (
                          'variable' => 'props',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 264,
                          'char' => 35,
                        ),
                        2 => 
                        array (
                          'variable' => 'property',
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 264,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 266,
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
                          'variable' => 'reflect',
                          'expr' => 
                          array (
                            'type' => 'new',
                            'class' => 'ReflectionClass',
                            'dynamic' => 0,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'variable',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 266,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 266,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 266,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 266,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 267,
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
                          'variable' => 'props',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reflect',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 267,
                              'char' => 37,
                            ),
                            'name' => 'getProperties',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bitwise_or',
                                  'left' => 
                                  array (
                                    'type' => 'bitwise_or',
                                    'left' => 
                                    array (
                                      'type' => 'static-constant-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'ReflectionProperty',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 268,
                                        'char' => 51,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'IS_PUBLIC',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 268,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 268,
                                      'char' => 51,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'static-constant-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'ReflectionProperty',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 269,
                                        'char' => 54,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'IS_PROTECTED',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 269,
                                        'char' => 54,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 269,
                                      'char' => 54,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 269,
                                    'char' => 54,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'static-constant-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'ReflectionProperty',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 271,
                                      'char' => 17,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'IS_PRIVATE',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 271,
                                      'char' => 17,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 271,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 271,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 271,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 271,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 271,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 273,
                      'char' => 19,
                    ),
                    3 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'props',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 273,
                        'char' => 39,
                      ),
                      'value' => 'property',
                      'reverse' => 0,
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
                              'value' => 'property',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 274,
                              'char' => 30,
                            ),
                            'name' => 'setAccessible',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 274,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 274,
                                'char' => 49,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 274,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 276,
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
                              'variable' => 'key',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'property',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 276,
                                  'char' => 40,
                                ),
                                'name' => 'getName',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 276,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 276,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 278,
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
                              'variable' => 'type',
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
                                      'value' => ' ',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 279,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 279,
                                    'char' => 26,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'scall',
                                      'dynamic-class' => 0,
                                      'class' => 'Reflection',
                                      'dynamic' => 0,
                                      'name' => 'getModifierNames',
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
                                              'value' => 'property',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 281,
                                              'char' => 38,
                                            ),
                                            'name' => 'getModifiers',
                                            'call-type' => 1,
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 282,
                                            'char' => 25,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 282,
                                          'char' => 25,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 283,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 283,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 283,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 283,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 285,
                          'char' => 23,
                        ),
                        3 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'concat-assign',
                              'variable' => 'output',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'str_repeat',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'space',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 285,
                                        'char' => 50,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 285,
                                      'char' => 50,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'tab',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 285,
                                        'char' => 55,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 285,
                                      'char' => 55,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 285,
                                  'char' => 57,
                                ),
                                'right' => 
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
                                        'type' => 'string',
                                        'value' => '-><span style=\':style\'>:key</span> (<span style=\':style\'>:type</span>) = ',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 285,
                                        'char' => 138,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 285,
                                      'char' => 138,
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
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ':style',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 285,
                                              'char' => 147,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'mcall',
                                              'variable' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'this',
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 285,
                                                'char' => 154,
                                              ),
                                              'name' => 'getStyle',
                                              'call-type' => 1,
                                              'parameters' => 
                                              array (
                                                0 => 
                                                array (
                                                  'parameter' => 
                                                  array (
                                                    'type' => 'string',
                                                    'value' => 'obj',
                                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                                    'line' => 285,
                                                    'char' => 167,
                                                  ),
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 285,
                                                  'char' => 167,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 285,
                                              'char' => 168,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 285,
                                            'char' => 168,
                                          ),
                                          1 => 
                                          array (
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ':key',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 285,
                                              'char' => 174,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'key',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 285,
                                              'char' => 179,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 285,
                                            'char' => 179,
                                          ),
                                          2 => 
                                          array (
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ':type',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 285,
                                              'char' => 186,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'type',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 285,
                                              'char' => 192,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 285,
                                            'char' => 192,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 285,
                                        'char' => 193,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 285,
                                      'char' => 193,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 285,
                                  'char' => 194,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 285,
                                'char' => 194,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 285,
                              'char' => 194,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 286,
                          'char' => 23,
                        ),
                        4 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'concat-assign',
                              'variable' => 'output',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 286,
                                    'char' => 39,
                                  ),
                                  'name' => 'output',
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
                                          'value' => 'property',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 286,
                                          'char' => 56,
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
                                              'value' => 'variable',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 286,
                                              'char' => 74,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 286,
                                            'char' => 74,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 286,
                                        'char' => 75,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 286,
                                      'char' => 75,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 286,
                                        'char' => 77,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 286,
                                      'char' => 77,
                                    ),
                                    2 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'add',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'tab',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 286,
                                          'char' => 83,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'int',
                                          'value' => '1',
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 286,
                                          'char' => 86,
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 286,
                                        'char' => 86,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 286,
                                      'char' => 86,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 286,
                                  'char' => 88,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\\n',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 286,
                                  'char' => 92,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 286,
                                'char' => 92,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 286,
                              'char' => 92,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 287,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 288,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 290,
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
                      'variable' => 'attr',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'get_class_methods',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'variable',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 290,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 290,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 290,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 290,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 291,
                  'char' => 15,
                ),
                5 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'output',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'str_repeat',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'space',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 291,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 291,
                              'char' => 42,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'tab',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 291,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 291,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 291,
                          'char' => 49,
                        ),
                        'right' => 
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
                                'type' => 'string',
                                'value' => ':class <b style=\':style\'>methods</b>: (<span style=\':style\'>:count</span>) (\\n',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 291,
                                'char' => 135,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 291,
                              'char' => 135,
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
                                    'key' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ':style',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 291,
                                      'char' => 144,
                                    ),
                                    'value' => 
                                    array (
                                      'type' => 'mcall',
                                      'variable' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 291,
                                        'char' => 151,
                                      ),
                                      'name' => 'getStyle',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'string',
                                            'value' => 'obj',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 291,
                                            'char' => 164,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 291,
                                          'char' => 164,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 291,
                                      'char' => 165,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 291,
                                    'char' => 165,
                                  ),
                                  1 => 
                                  array (
                                    'key' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ':class',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 291,
                                      'char' => 173,
                                    ),
                                    'value' => 
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
                                            'value' => 'variable',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 291,
                                            'char' => 193,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 291,
                                          'char' => 193,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 291,
                                      'char' => 194,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 291,
                                    'char' => 194,
                                  ),
                                  2 => 
                                  array (
                                    'key' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ':count',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 291,
                                      'char' => 202,
                                    ),
                                    'value' => 
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
                                            'value' => 'attr',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 291,
                                            'char' => 214,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 291,
                                          'char' => 214,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 291,
                                      'char' => 215,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 291,
                                    'char' => 215,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 291,
                                'char' => 216,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 291,
                              'char' => 216,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 291,
                          'char' => 217,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 291,
                        'char' => 217,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 291,
                      'char' => 217,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 293,
                  'char' => 14,
                ),
                6 => 
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
                                'value' => 'variable',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 293,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 293,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 293,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 293,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 293,
                            'char' => 51,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'methods',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 293,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 293,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 293,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 293,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'str_repeat',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'space',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 294,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 294,
                                  'char' => 46,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'tab',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 294,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 294,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 294,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '[already listed]\\n',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 294,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 294,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 294,
                          'char' => 73,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 295,
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
                        'value' => 'attr',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 296,
                        'char' => 35,
                      ),
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
                              'assign-type' => 'object-property-append',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'methods',
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
                                      'value' => 'variable',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 297,
                                      'char' => 61,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 297,
                                    'char' => 61,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 297,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 297,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 299,
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
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 299,
                              'char' => 31,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '__construct',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 299,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 299,
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'output',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'str_repeat',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'space',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 300,
                                            'char' => 54,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 300,
                                          'char' => 54,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'add',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'tab',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 300,
                                              'char' => 60,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '1',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 300,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 300,
                                            'char' => 63,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 300,
                                          'char' => 63,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 300,
                                      'char' => 65,
                                    ),
                                    'right' => 
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
                                            'type' => 'string',
                                            'value' => '-><span style=\':style\'>:method</span>(); [<b style=\':style\'>constructor</b>]\\n',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 300,
                                            'char' => 151,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 300,
                                          'char' => 151,
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
                                                'key' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ':style',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 300,
                                                  'char' => 160,
                                                ),
                                                'value' => 
                                                array (
                                                  'type' => 'mcall',
                                                  'variable' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'this',
                                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                                    'line' => 300,
                                                    'char' => 167,
                                                  ),
                                                  'name' => 'getStyle',
                                                  'call-type' => 1,
                                                  'parameters' => 
                                                  array (
                                                    0 => 
                                                    array (
                                                      'parameter' => 
                                                      array (
                                                        'type' => 'string',
                                                        'value' => 'obj',
                                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                                        'line' => 300,
                                                        'char' => 180,
                                                      ),
                                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                                      'line' => 300,
                                                      'char' => 180,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 300,
                                                  'char' => 181,
                                                ),
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 300,
                                                'char' => 181,
                                              ),
                                              1 => 
                                              array (
                                                'key' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ':method',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 300,
                                                  'char' => 190,
                                                ),
                                                'value' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'value',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 300,
                                                  'char' => 197,
                                                ),
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 300,
                                                'char' => 197,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 300,
                                            'char' => 198,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 300,
                                          'char' => 198,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 300,
                                      'char' => 199,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 300,
                                    'char' => 199,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 300,
                                  'char' => 199,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 301,
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
                                  'variable' => 'output',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'str_repeat',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'space',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 302,
                                            'char' => 54,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 302,
                                          'char' => 54,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'add',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'tab',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 302,
                                              'char' => 60,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '1',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 302,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 302,
                                            'char' => 63,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 302,
                                          'char' => 63,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 302,
                                      'char' => 65,
                                    ),
                                    'right' => 
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
                                            'type' => 'string',
                                            'value' => '-><span style=\':style\'>:method</span>();\\n',
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 302,
                                            'char' => 115,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 302,
                                          'char' => 115,
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
                                                'key' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ':style',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 302,
                                                  'char' => 124,
                                                ),
                                                'value' => 
                                                array (
                                                  'type' => 'mcall',
                                                  'variable' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'this',
                                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                                    'line' => 302,
                                                    'char' => 131,
                                                  ),
                                                  'name' => 'getStyle',
                                                  'call-type' => 1,
                                                  'parameters' => 
                                                  array (
                                                    0 => 
                                                    array (
                                                      'parameter' => 
                                                      array (
                                                        'type' => 'string',
                                                        'value' => 'obj',
                                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                                        'line' => 302,
                                                        'char' => 144,
                                                      ),
                                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                                      'line' => 302,
                                                      'char' => 144,
                                                    ),
                                                  ),
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 302,
                                                  'char' => 145,
                                                ),
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 302,
                                                'char' => 145,
                                              ),
                                              1 => 
                                              array (
                                                'key' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ':method',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 302,
                                                  'char' => 154,
                                                ),
                                                'value' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'value',
                                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                                  'line' => 302,
                                                  'char' => 161,
                                                ),
                                                'file' => '/app/phalcon/Debug/Dump.zep',
                                                'line' => 302,
                                                'char' => 161,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 302,
                                            'char' => 162,
                                          ),
                                          'file' => '/app/phalcon/Debug/Dump.zep',
                                          'line' => 302,
                                          'char' => 162,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 302,
                                      'char' => 163,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 302,
                                    'char' => 163,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 302,
                                  'char' => 163,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 303,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 304,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 306,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'str_repeat',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'space',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 306,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 306,
                                  'char' => 46,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'tab',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 306,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 306,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 306,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ')\\n',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 306,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 306,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 306,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 307,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 309,
                  'char' => 18,
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
                        'value' => 'output',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 309,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'str_repeat',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'space',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 309,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 309,
                            'char' => 45,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'sub',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'tab',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 309,
                                'char' => 51,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 309,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 309,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 309,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 309,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 309,
                      'char' => 56,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 309,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 309,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 310,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 312,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_int',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 312,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 312,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 312,
                'char' => 29,
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
                      'type' => 'variable',
                      'value' => 'output',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 313,
                      'char' => 27,
                    ),
                    'right' => 
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
                            'type' => 'string',
                            'value' => '<b style=\':style\'>Integer</b> (<span style=\':style\'>:var</span>)',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 313,
                            'char' => 99,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 313,
                          'char' => 99,
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
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':style',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 313,
                                  'char' => 108,
                                ),
                                'value' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 313,
                                    'char' => 115,
                                  ),
                                  'name' => 'getStyle',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'int',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 313,
                                        'char' => 128,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 313,
                                      'char' => 128,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 313,
                                  'char' => 129,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 313,
                                'char' => 129,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':var',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 313,
                                  'char' => 135,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'variable',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 313,
                                  'char' => 145,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 313,
                                'char' => 145,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 313,
                            'char' => 146,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 313,
                          'char' => 146,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 313,
                      'char' => 147,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 313,
                    'char' => 147,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 314,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 316,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_float',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 316,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 316,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 316,
                'char' => 31,
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
                      'type' => 'variable',
                      'value' => 'output',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 317,
                      'char' => 27,
                    ),
                    'right' => 
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
                            'type' => 'string',
                            'value' => '<b style=\':style\'>Float</b> (<span style=\':style\'>:var</span>)',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 317,
                            'char' => 97,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 317,
                          'char' => 97,
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
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':style',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 317,
                                  'char' => 106,
                                ),
                                'value' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 317,
                                    'char' => 113,
                                  ),
                                  'name' => 'getStyle',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'float',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 317,
                                        'char' => 128,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 317,
                                      'char' => 128,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 317,
                                  'char' => 129,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 317,
                                'char' => 129,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':var',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 317,
                                  'char' => 135,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'variable',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 317,
                                  'char' => 145,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 317,
                                'char' => 145,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 317,
                            'char' => 146,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 317,
                          'char' => 146,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 317,
                      'char' => 147,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 317,
                    'char' => 147,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 318,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 320,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_numeric',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 320,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 320,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 320,
                'char' => 33,
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
                      'type' => 'variable',
                      'value' => 'output',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 321,
                      'char' => 27,
                    ),
                    'right' => 
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
                            'type' => 'string',
                            'value' => '<b style=\':style\'>Numeric string</b> (<span style=\':style\'>:length</span>) \\"<span style=\':style\'>:var</span>\\"',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 321,
                            'char' => 146,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 321,
                          'char' => 146,
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
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':style',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 321,
                                  'char' => 155,
                                ),
                                'value' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 321,
                                    'char' => 162,
                                  ),
                                  'name' => 'getStyle',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'num',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 321,
                                        'char' => 175,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 321,
                                      'char' => 175,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 321,
                                  'char' => 176,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 321,
                                'char' => 176,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':length',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 321,
                                  'char' => 185,
                                ),
                                'value' => 
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
                                        'value' => 'variable',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 321,
                                        'char' => 202,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 321,
                                      'char' => 202,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 321,
                                  'char' => 203,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 321,
                                'char' => 203,
                              ),
                              2 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':var',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 321,
                                  'char' => 209,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'variable',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 321,
                                  'char' => 219,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 321,
                                'char' => 219,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 321,
                            'char' => 220,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 321,
                          'char' => 220,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 321,
                      'char' => 221,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 321,
                    'char' => 221,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 322,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 324,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_string',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 324,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 324,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 324,
                'char' => 32,
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
                      'type' => 'variable',
                      'value' => 'output',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 325,
                      'char' => 27,
                    ),
                    'right' => 
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
                            'type' => 'string',
                            'value' => '<b style=\':style\'>String</b> (<span style=\':style\'>:length</span>) \\"<span style=\':style\'>:var</span>\\"',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 325,
                            'char' => 138,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 325,
                          'char' => 138,
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
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':style',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 325,
                                  'char' => 147,
                                ),
                                'value' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 325,
                                    'char' => 154,
                                  ),
                                  'name' => 'getStyle',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'str',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 325,
                                        'char' => 167,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 325,
                                      'char' => 167,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 325,
                                  'char' => 168,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 325,
                                'char' => 168,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':length',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 325,
                                  'char' => 177,
                                ),
                                'value' => 
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
                                        'value' => 'variable',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 325,
                                        'char' => 194,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 325,
                                      'char' => 194,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 325,
                                  'char' => 195,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 325,
                                'char' => 195,
                              ),
                              2 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':var',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 325,
                                  'char' => 201,
                                ),
                                'value' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'nl2br',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'htmlentities',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'variable',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 325,
                                              'char' => 230,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 325,
                                            'char' => 230,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'constant',
                                              'value' => 'ENT_IGNORE',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 325,
                                              'char' => 242,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 325,
                                            'char' => 242,
                                          ),
                                          2 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'utf-8',
                                              'file' => '/app/phalcon/Debug/Dump.zep',
                                              'line' => 325,
                                              'char' => 249,
                                            ),
                                            'file' => '/app/phalcon/Debug/Dump.zep',
                                            'line' => 325,
                                            'char' => 249,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 325,
                                        'char' => 250,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 325,
                                      'char' => 250,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 325,
                                  'char' => 251,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 325,
                                'char' => 251,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 325,
                            'char' => 252,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 325,
                          'char' => 252,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 325,
                      'char' => 253,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 325,
                    'char' => 253,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 326,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 328,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_bool',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 328,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 328,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 328,
                'char' => 30,
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
                      'type' => 'variable',
                      'value' => 'output',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 329,
                      'char' => 27,
                    ),
                    'right' => 
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
                            'type' => 'string',
                            'value' => '<b style=\':style\'>Boolean</b> (<span style=\':style\'>:var</span>)',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 329,
                            'char' => 99,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 329,
                          'char' => 99,
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
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':style',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 329,
                                  'char' => 108,
                                ),
                                'value' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 329,
                                    'char' => 115,
                                  ),
                                  'name' => 'getStyle',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'bool',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 329,
                                        'char' => 129,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 329,
                                      'char' => 129,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 329,
                                  'char' => 130,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 329,
                                'char' => 130,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':var',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 329,
                                  'char' => 136,
                                ),
                                'value' => 
                                array (
                                  'type' => 'list',
                                  'left' => 
                                  array (
                                    'type' => 'ternary',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'variable',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 329,
                                      'char' => 148,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'TRUE',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 329,
                                      'char' => 155,
                                    ),
                                    'extra' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'FALSE',
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 329,
                                      'char' => 162,
                                    ),
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 329,
                                    'char' => 162,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 329,
                                  'char' => 163,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 329,
                                'char' => 163,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 329,
                            'char' => 164,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 329,
                          'char' => 164,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 329,
                      'char' => 165,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 329,
                    'char' => 165,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 330,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 332,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_null',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 332,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 332,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 332,
                'char' => 30,
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
                      'type' => 'variable',
                      'value' => 'output',
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 333,
                      'char' => 27,
                    ),
                    'right' => 
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
                            'type' => 'string',
                            'value' => '<b style=\':style\'>NULL</b>',
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 333,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 333,
                          'char' => 61,
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
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':style',
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 333,
                                  'char' => 70,
                                ),
                                'value' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 333,
                                    'char' => 77,
                                  ),
                                  'name' => 'getStyle',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'null',
                                        'file' => '/app/phalcon/Debug/Dump.zep',
                                        'line' => 333,
                                        'char' => 91,
                                      ),
                                      'file' => '/app/phalcon/Debug/Dump.zep',
                                      'line' => 333,
                                      'char' => 91,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 333,
                                  'char' => 92,
                                ),
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 333,
                                'char' => 92,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 333,
                            'char' => 93,
                          ),
                          'file' => '/app/phalcon/Debug/Dump.zep',
                          'line' => 333,
                          'char' => 93,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 333,
                      'char' => 94,
                    ),
                    'file' => '/app/phalcon/Debug/Dump.zep',
                    'line' => 333,
                    'char' => 94,
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 334,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 336,
              'char' => 14,
            ),
            11 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'output',
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 336,
                  'char' => 23,
                ),
                'right' => 
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
                        'type' => 'string',
                        'value' => '(<span style=\':style\'>:var</span>)',
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 336,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 336,
                      'char' => 65,
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
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => ':style',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 336,
                              'char' => 74,
                            ),
                            'value' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Debug/Dump.zep',
                                'line' => 336,
                                'char' => 81,
                              ),
                              'name' => 'getStyle',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'other',
                                    'file' => '/app/phalcon/Debug/Dump.zep',
                                    'line' => 336,
                                    'char' => 96,
                                  ),
                                  'file' => '/app/phalcon/Debug/Dump.zep',
                                  'line' => 336,
                                  'char' => 96,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 336,
                              'char' => 97,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 336,
                            'char' => 97,
                          ),
                          1 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => ':var',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 336,
                              'char' => 103,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'variable',
                              'file' => '/app/phalcon/Debug/Dump.zep',
                              'line' => 336,
                              'char' => 113,
                            ),
                            'file' => '/app/phalcon/Debug/Dump.zep',
                            'line' => 336,
                            'char' => 113,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Dump.zep',
                        'line' => 336,
                        'char' => 114,
                      ),
                      'file' => '/app/phalcon/Debug/Dump.zep',
                      'line' => 336,
                      'char' => 114,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Dump.zep',
                  'line' => 336,
                  'char' => 115,
                ),
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 336,
                'char' => 115,
              ),
              'file' => '/app/phalcon/Debug/Dump.zep',
              'line' => 337,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prepare an HTML string of information about a single variable.
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
                'file' => '/app/phalcon/Debug/Dump.zep',
                'line' => 201,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Dump.zep',
            'line' => 201,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Dump.zep',
          'line' => 200,
          'last-line' => 338,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Debug/Dump.zep',
      'line' => 36,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Debug/Dump.zep',
    'line' => 36,
    'char' => 5,
  ),
);