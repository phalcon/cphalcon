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
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate\\Adapter',
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
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
        'name' => 'ArrayAccess',
        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
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
        'name' => 'Phalcon\\Translate\\Exception',
        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
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
        'name' => 'Phalcon\\Translate\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
        'line' => 15,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
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
        'name' => 'Phalcon\\Translate\\InterpolatorFactory',
        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
        'line' => 16,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
    'line' => 35,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Translate\\Adapter\\Gettext
 *
 * ```php
 * use Phalcon\\Translate\\Adapter\\Gettext;
 *
 * $adapter = new Gettext(
 *     [
 *         "locale"        => "de_DE.UTF-8",
 *         "defaultDomain" => "translations",
 *         "directory"     => "/path/to/application/locales",
 *         "category"      => LC_MESSAGES,
 *     ]
 * );
 * ```
 *
 * Allows translate using gettext
 *',
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
    'line' => 36,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Gettext',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
        'line' => 37,
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
          'name' => 'category',
          'docblock' => '**
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 41,
              'char' => 30,
            ),
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
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
          'name' => 'defaultDomain',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 46,
              'char' => 35,
            ),
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
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
          'name' => 'directory',
          'docblock' => '**
     * @var string|array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 51,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 55,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'locale',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 56,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 60,
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
              'name' => 'interpolator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'InterpolatorFactory',
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 61,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 61,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 61,
              'char' => 83,
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
                  'type' => 'not',
                  'left' => 
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
                          'value' => 'gettext',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 63,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 63,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 63,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 63,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 63,
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
                          'value' => 'This class requires the gettext extension for PHP',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 66,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 66,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 66,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 67,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 69,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'interpolator',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 69,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 69,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 69,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 69,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 69,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 71,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 71,
                  'char' => 14,
                ),
                'name' => 'prepareOptions',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 71,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 71,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 71,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 72,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Translate\\Adapter\\Gettext constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 62,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 61,
          'last-line' => 76,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'exists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 77,
              'char' => 41,
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
                  'variable' => 'result',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 79,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 81,
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
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 81,
                      'char' => 27,
                    ),
                    'name' => 'query',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 81,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 81,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 81,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 81,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 83,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'result',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 83,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'index',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 83,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 83,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether is defined a translation key in the internal array
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
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 77,
          'last-line' => 90,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'nquery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'msgid1',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 91,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'msgid2',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 91,
              'char' => 58,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'count',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 91,
              'char' => 70,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 91,
                'char' => 91,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 91,
              'char' => 91,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'domain',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 91,
                'char' => 114,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 91,
              'char' => 114,
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
                  'variable' => 'translation',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 93,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 95,
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
                  'type' => 'variable',
                  'value' => 'domain',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 95,
                  'char' => 20,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 95,
                'char' => 20,
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
                      'variable' => 'translation',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'ngettext',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'msgid1',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 96,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 96,
                            'char' => 46,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'msgid2',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 96,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 96,
                            'char' => 54,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'count',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 96,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 96,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 96,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 96,
                      'char' => 62,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 97,
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
                      'variable' => 'translation',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'dngettext',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'domain',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 98,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 98,
                            'char' => 47,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'msgid1',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 98,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 98,
                            'char' => 55,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'msgid2',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 98,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 98,
                            'char' => 63,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'count',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 98,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 98,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 98,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 98,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 99,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 101,
              'char' => 14,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 101,
                  'char' => 21,
                ),
                'name' => 'replacePlaceholders',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translation',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 101,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 101,
                    'char' => 53,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 101,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 101,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 101,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 102,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * The plural version of gettext().
     * Some languages have more than one form for plural messages dependent on
     * the count.
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
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 92,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 92,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 91,
          'last-line' => 112,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'query',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 113,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 113,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 113,
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
                  'variable' => 'translation',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 115,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 117,
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
                  'variable' => 'translation',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'gettext',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 117,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 117,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 117,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 117,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 119,
              'char' => 14,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 119,
                  'char' => 21,
                ),
                'name' => 'replacePlaceholders',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translation',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 119,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 119,
                    'char' => 53,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 119,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 119,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 119,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 120,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the translation related to the given key.
     *
     * ```php
     * $translator->query("你好 %name%！", ["name" => "Phalcon"]);
     * ```
     *
     * @param array   placeholders
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
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 113,
          'last-line' => 124,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'resetDomain',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'textdomain',
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
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 128,
                        'char' => 18,
                      ),
                      'name' => 'getDefaultDomain',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 129,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 129,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 129,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 130,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default domain
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
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 126,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 126,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 125,
          'last-line' => 134,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultDomain',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'domain',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 135,
              'char' => 52,
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
                  'property' => 'defaultDomain',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'domain',
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 137,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 137,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 138,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the domain default to search within when calls are made to gettext()
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 136,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 135,
          'last-line' => 157,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDirectory',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'directory',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 158,
              'char' => 47,
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
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 160,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 160,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 162,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'directory',
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 162,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 162,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 162,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 164,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 166,
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
                  'property' => 'directory',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'directory',
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 166,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 166,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 168,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'directory',
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 168,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 168,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 168,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 168,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'directory',
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 169,
                    'char' => 41,
                  ),
                  'key' => 'key',
                  'value' => 'value',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'fcall',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'bindtextdomain',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 170,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 170,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                              'line' => 170,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 170,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 170,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 171,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 172,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'bindtextdomain',
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
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 174,
                            'char' => 22,
                          ),
                          'name' => 'getDefaultDomain',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 174,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 174,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'directory',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 176,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 176,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 176,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 177,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 178,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the path for a domain
     *
     * ```php
     * // Set the directory path
     * $gettext->setDirectory("/path/to/the/messages");
     *
     * // Set the domains and directories path
     * $gettext->setDirectory(
     *     [
     *         "messages" => "/path/to/the/messages",
     *         "another"  => "/path/to/the/another",
     *     ]
     * );
     * ```
     *
     * @param string|array directory The directory path or an array of directories and domains
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 158,
          'last-line' => 182,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDomain',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'domain',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 183,
              'char' => 41,
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
                'name' => 'textdomain',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'domain',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 185,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 185,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 185,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Changes the current domain (i.e. the translation file)
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
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 184,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 184,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 183,
          'last-line' => 198,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLocale',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'category',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 199,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'locale',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 199,
              'char' => 60,
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
                  'property' => 'locale',
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
                          'value' => 'setlocale',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 202,
                          'char' => 22,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 202,
                        'char' => 22,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'func_get_args',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 204,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 204,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 204,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 204,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 206,
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
                  'property' => 'category',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'category',
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 206,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 206,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 208,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'putenv',
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
                        'type' => 'string',
                        'value' => 'LC_ALL=',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 208,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 208,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'locale',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 208,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 208,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 208,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 208,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 208,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 209,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'putenv',
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
                        'type' => 'string',
                        'value' => 'LANG=',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 209,
                        'char' => 22,
                      ),
                      'right' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 209,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'locale',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 209,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 209,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 209,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 209,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 209,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 210,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'putenv',
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
                        'type' => 'string',
                        'value' => 'LANGUAGE=',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 210,
                        'char' => 26,
                      ),
                      'right' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 210,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'locale',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 210,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 210,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 210,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 210,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 210,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 211,
              'char' => 17,
            ),
            5 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'setlocale',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'constant',
                      'value' => 'LC_ALL',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 211,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 211,
                    'char' => 25,
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
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 211,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'locale',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 211,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 211,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 211,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 211,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 213,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 213,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'locale',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 213,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 213,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 214,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets locale information
     *
     * ```php
     * // Set locale to Dutch
     * $gettext->setLocale(LC_ALL, "nl_NL");
     *
     * // Try different possible locale names for german
     * $gettext->setLocale(LC_ALL, "de_DE@euro", "de_DE", "de", "ge");
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
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 199,
                'char' => 72,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 200,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 200,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 199,
          'last-line' => 218,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getOptionsDefault',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
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
                      'value' => 'category',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 222,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'constant',
                      'value' => 'LC_ALL',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 222,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 222,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'defaultDomain',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 223,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 224,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 224,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 224,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 225,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets default options
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
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 220,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 220,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 219,
          'last-line' => 229,
          'char' => 22,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'prepareOptions',
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
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 230,
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
                'type' => 'unlikely',
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
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 232,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'locale',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 232,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 232,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 232,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 232,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 232,
                'char' => 44,
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
                          'value' => 'Parameter \'locale\' is required',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 233,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 233,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 233,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 234,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 236,
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 236,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'directory',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 236,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 236,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 236,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 236,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 236,
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
                          'value' => 'Parameter \'directory\' is required',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 237,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 237,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 237,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 238,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 240,
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
                  'variable' => 'options',
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                            'line' => 241,
                            'char' => 18,
                          ),
                          'name' => 'getOptionsDefault',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 241,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 241,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                          'line' => 243,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 243,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 243,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 243,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 245,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 245,
                  'char' => 14,
                ),
                'name' => 'setLocale',
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
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 246,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'category',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 246,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 246,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 246,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 247,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'locale',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 247,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 248,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 248,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 248,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 250,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 250,
                  'char' => 14,
                ),
                'name' => 'setDefaultDomain',
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
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 251,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'defaultDomain',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 251,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 252,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 252,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 252,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 254,
              'char' => 12,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 254,
                  'char' => 14,
                ),
                'name' => 'setDirectory',
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
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 255,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'directory',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 255,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 256,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 256,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 256,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 258,
              'char' => 12,
            ),
            6 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                  'line' => 258,
                  'char' => 14,
                ),
                'name' => 'setDomain',
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
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 259,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'defaultDomain',
                        'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                        'line' => 259,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                      'line' => 260,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                    'line' => 260,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
                'line' => 260,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
              'line' => 261,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Validator for constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
            'line' => 231,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
          'line' => 230,
          'last-line' => 262,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
      'line' => 36,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Translate/Adapter/Gettext.zep',
    'line' => 36,
    'char' => 5,
  ),
);