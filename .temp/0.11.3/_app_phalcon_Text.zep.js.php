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
    'file' => '/app/phalcon/Text.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Text.zep',
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
        'name' => 'Phalcon\\Helper\\Str',
        'file' => '/app/phalcon/Text.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Text.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Provides utilities to work with texts
 *',
    'file' => '/app/phalcon/Text.zep',
    'line' => 18,
    'char' => 8,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Text',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 36,
              'char' => 49,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 36,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 36,
              'char' => 71,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'camelize',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 38,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 38,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 38,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 38,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 38,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Converts strings to camelize style
     *
     * ```php
     * echo Phalcon\\Text::camelize("coco_bongo"); // CocoBongo
     * echo Phalcon\\Text::camelize("co_co-bon_go", "-"); // Co_coBon_go
     * echo Phalcon\\Text::camelize("co_co-bon_go", "_-"); // CoCoBonGo
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 37,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 37,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 36,
          'last-line' => 62,
          'char' => 26,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
                  'variable' => 'args',
                  'file' => '/app/phalcon/Text.zep',
                  'line' => 66,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 68,
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
                  'variable' => 'args',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'func_get_args',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 68,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Text.zep',
                  'line' => 68,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 70,
              'char' => 14,
            ),
            2 => 
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
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Helper\\\\Str::concat',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 70,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 70,
                    'char' => 67,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'args',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 70,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 70,
                    'char' => 73,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 70,
                'char' => 74,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Concatenates strings using the separator only once without duplication in
     * places concatenation
     *
     * ```php
     * $str = Phalcon\\Text::concat(
     *     "/",
     *     "/tmp/",
     *     "/folder_1/",
     *     "/folder_2",
     *     "folder_3/"
     * );
     *
     * // /tmp/folder_1/folder_2/folder_3/
     * echo $str;
     * ```
     *
     * @param string separator
     * @param string a
     * @param string b
     * @param string ...N
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 65,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 65,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 64,
          'last-line' => 93,
          'char' => 26,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 95,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 96,
                'char' => 34,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 96,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 97,
                'char' => 35,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 97,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 99,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 99,
              'char' => 5,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'dynamic',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 101,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 101,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'leftDelimiter',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 101,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 101,
                    'char' => 48,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rightDelimiter',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 101,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 101,
                    'char' => 64,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'separator',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 101,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 101,
                    'char' => 75,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 101,
                'char' => 76,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 102,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates random text in accordance with the template
     *
     * ```php
     * // Hi my name is a Bob
     * echo Phalcon\\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hi my name is a Jon
     * echo Phalcon\\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hello my name is a Bob
     * echo Phalcon\\Text::dynamic("{Hi|Hello}, my name is a {Bob|Mark|Jon}!");
     *
     * // Hello my name is a Zyxep
     * echo Phalcon\\Text::dynamic(
     *     "[Hi/Hello], my name is a [Zyxep/Mark]!",
     *     "[", "]",
     *     "/"
     * );
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 100,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 100,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 94,
          'last-line' => 112,
          'char' => 26,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 113,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'end',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 113,
              'char' => 60,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 113,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 113,
              'char' => 84,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'endsWith',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 115,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 115,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'end',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 115,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 115,
                    'char' => 39,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ignoreCase',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 115,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 115,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 115,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 116,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a string ends with a given string
     *
     * ```php
     * echo Phalcon\\Text::endsWith("Hello", "llo"); // true
     * echo Phalcon\\Text::endsWith("Hello", "LLO", false); // false
     * echo Phalcon\\Text::endsWith("Hello", "LLO"); // true
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
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Text.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 113,
          'last-line' => 125,
          'char' => 26,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 126,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'humanize',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 128,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 128,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 128,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Makes an underscored or dashed phrase human-readable
     *
     * ```php
     * echo Phalcon\\Text::humanize("start-a-horse"); // "start a horse"
     * echo Phalcon\\Text::humanize("five_cats"); // "five cats"
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 127,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 126,
          'last-line' => 139,
          'char' => 26,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 140,
              'char' => 49,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 140,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 140,
              'char' => 71,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'increment',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 142,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 142,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'separator',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 142,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 142,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 142,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a number to a string or increment that number if it already is
     * defined
     *
     * ```php
     * echo Phalcon\\Text::increment("a"); // "a_1"
     * echo Phalcon\\Text::increment("a_1"); // "a_2"
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 141,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 140,
          'last-line' => 152,
          'char' => 26,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 153,
              'char' => 46,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 153,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 153,
              'char' => 72,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'lower',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 155,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 155,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'encoding',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 155,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 155,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 155,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 156,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Lowercases a string, this function makes use of the mbstring extension if
     * available
     *
     * ```php
     * echo Phalcon\\Text::lower("HELLO"); // hello
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 154,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 154,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 153,
          'last-line' => 166,
          'char' => 26,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 167,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'start',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 167,
              'char' => 64,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 167,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 167,
              'char' => 88,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'startsWith',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 169,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 169,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'start',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 169,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 169,
                    'char' => 43,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ignoreCase',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 169,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 169,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 169,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 170,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a string starts with a given string
     *
     * ```php
     * echo Phalcon\\Text::startsWith("Hello", "He"); // true
     * echo Phalcon\\Text::startsWith("Hello", "he", false); // false
     * echo Phalcon\\Text::startsWith("Hello", "he"); // true
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
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Text.zep',
                'line' => 168,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 168,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 167,
          'last-line' => 182,
          'char' => 26,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 183,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 183,
              'char' => 47,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 183,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 183,
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'random',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 185,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 185,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'length',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 185,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 185,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 185,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random string based on the given type. Type is one of the
     * RANDOM_* constants
     *
     * ```php
     * use Phalcon\\Text;
     *
     * // "aloiwkqz"
     * echo Text::random(Text::RANDOM_ALNUM);
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 184,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 184,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 183,
          'last-line' => 198,
          'char' => 26,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 199,
              'char' => 54,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'reduceSlashes',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 201,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 201,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 201,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 202,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reduces multiple slashes in a string to single slashes
     *
     * ```php
     * // foo/bar/baz
     * echo Phalcon\\Text::reduceSlashes("foo//bar/baz");
     *
     * // http://foo.bar/baz/buz
     * echo Phalcon\\Text::reduceSlashes("http://foo.bar///baz/buz");
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 200,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 200,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 199,
          'last-line' => 211,
          'char' => 26,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 212,
              'char' => 51,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 212,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 212,
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
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'uncamelize',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 214,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 214,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 214,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 214,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 214,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 215,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Uncamelize strings which are camelized
     *
     * ```php
     * echo Phalcon\\Text::uncamelize("CocoBongo"); // coco_bongo
     * echo Phalcon\\Text::uncamelize("CocoBongo", "-"); // coco-bongo
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 213,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 213,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 212,
          'last-line' => 224,
          'char' => 26,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 225,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'underscore',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 227,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 227,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 227,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 228,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Makes a phrase underscored instead of spaced
     *
     * ```php
     * echo Phalcon\\Text::underscore("look behind"); // "look_behind"
     * echo Phalcon\\Text::underscore("Awesome Phalcon"); // "Awesome_Phalcon"
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 226,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 226,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 225,
          'last-line' => 237,
          'char' => 26,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
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
              'file' => '/app/phalcon/Text.zep',
              'line' => 238,
              'char' => 46,
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 238,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Text.zep',
              'line' => 238,
              'char' => 72,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Str',
                'dynamic' => 0,
                'name' => 'upper',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 240,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 240,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'encoding',
                      'file' => '/app/phalcon/Text.zep',
                      'line' => 240,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Text.zep',
                    'line' => 240,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Text.zep',
                'line' => 240,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Text.zep',
              'line' => 241,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Uppercases a string, this function makes use of the mbstring extension if
     * available
     *
     * ```php
     * echo Phalcon\\Text::upper("hello"); // HELLO
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
                'file' => '/app/phalcon/Text.zep',
                'line' => 239,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Text.zep',
            'line' => 239,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 238,
          'last-line' => 242,
          'char' => 26,
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
            'file' => '/app/phalcon/Text.zep',
            'line' => 20,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 21,
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
            'file' => '/app/phalcon/Text.zep',
            'line' => 21,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 22,
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
            'file' => '/app/phalcon/Text.zep',
            'line' => 22,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 23,
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
            'file' => '/app/phalcon/Text.zep',
            'line' => 23,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 24,
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
            'file' => '/app/phalcon/Text.zep',
            'line' => 24,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 25,
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
            'file' => '/app/phalcon/Text.zep',
            'line' => 25,
            'char' => 30,
          ),
          'file' => '/app/phalcon/Text.zep',
          'line' => 35,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Text.zep',
      'line' => 18,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Text.zep',
    'line' => 18,
    'char' => 14,
  ),
);