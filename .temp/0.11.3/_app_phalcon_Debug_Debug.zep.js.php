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
    'file' => '/app/phalcon/Debug/Debug.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Debug',
    'file' => '/app/phalcon/Debug/Debug.zep',
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
        'name' => 'ErrorException',
        'file' => '/app/phalcon/Debug/Debug.zep',
        'line' => 13,
        'char' => 19,
      ),
    ),
    'file' => '/app/phalcon/Debug/Debug.zep',
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
        'file' => '/app/phalcon/Debug/Debug.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Debug/Debug.zep',
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
        'name' => 'Phalcon\\Version',
        'file' => '/app/phalcon/Debug/Debug.zep',
        'line' => 15,
        'char' => 20,
      ),
    ),
    'file' => '/app/phalcon/Debug/Debug.zep',
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
        'name' => 'Phalcon\\Tag',
        'file' => '/app/phalcon/Debug/Debug.zep',
        'line' => 16,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Debug/Debug.zep',
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
        'name' => 'ReflectionClass',
        'file' => '/app/phalcon/Debug/Debug.zep',
        'line' => 17,
        'char' => 20,
      ),
    ),
    'file' => '/app/phalcon/Debug/Debug.zep',
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
        'name' => 'ReflectionFunction',
        'file' => '/app/phalcon/Debug/Debug.zep',
        'line' => 18,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Debug/Debug.zep',
    'line' => 22,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Provides debug capabilities to Phalcon applications
 *',
    'file' => '/app/phalcon/Debug/Debug.zep',
    'line' => 23,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Debug',
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
          'name' => 'blacklist',
          'default' => 
          array (
            'type' => 'array',
            'left' => 
            array (
              0 => 
              array (
                'key' => 
                array (
                  'type' => 'string',
                  'value' => 'request',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 28,
                  'char' => 36,
                ),
                'value' => 
                array (
                  'type' => 'empty-array',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 28,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 28,
                'char' => 40,
              ),
              1 => 
              array (
                'key' => 
                array (
                  'type' => 'string',
                  'value' => 'server',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 28,
                  'char' => 49,
                ),
                'value' => 
                array (
                  'type' => 'empty-array',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 28,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 28,
                'char' => 53,
              ),
            ),
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 28,
            'char' => 54,
          ),
          'docblock' => '**
     * @var array
    *',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 30,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'data',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 34,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'hideDocumentRoot',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 35,
            'char' => 39,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 39,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
            1 => 'static',
          ),
          'type' => 'property',
          'name' => 'isActive',
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 44,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'showBackTrace',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 45,
            'char' => 35,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 49,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'showFileFragment',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 50,
            'char' => 39,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 54,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'showFiles',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 55,
            'char' => 31,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 59,
          'char' => 5,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'uri',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'https://assets.phalconphp.com/debug/4.0.x/',
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 60,
            'char' => 63,
          ),
          'docblock' => '**
     * @var string
    *',
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 64,
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
          'name' => 'clearVars',
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
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 67,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 67,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 69,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 69,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 70,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Clears are variables added previously
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 66,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 66,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 66,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 65,
          'last-line' => 74,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'debugVar',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'varz',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 75,
              'char' => 34,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 75,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 75,
              'char' => 53,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
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
                          'value' => 'varz',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 78,
                          'char' => 17,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 78,
                        'char' => 17,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'debug_backtrace',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 79,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 79,
                        'char' => 30,
                      ),
                      2 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'time',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 81,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 81,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 81,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 81,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 83,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 83,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a variable to the debug output
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 76,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 76,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 76,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 75,
          'last-line' => 88,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCssSources',
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
                  'variable' => 'uri',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 91,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'sources',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 91,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
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
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 93,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 93,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 93,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 93,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 95,
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
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<link rel=\'stylesheet\' type=\'text/css\' href=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 95,
                        'char' => 70,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 95,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 95,
                      'char' => 76,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'bower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css\' />',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 95,
                      'char' => 146,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 95,
                    'char' => 146,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 95,
                  'char' => 146,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 96,
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
                  'operator' => 'concat-assign',
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<link rel=\'stylesheet\' type=\'text/css\' href=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 96,
                        'char' => 69,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 96,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 96,
                      'char' => 75,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'bower_components/jquery-ui/themes/ui-lightness/theme.css\' />',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 96,
                      'char' => 137,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 96,
                    'char' => 137,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 96,
                  'char' => 137,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 97,
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
                  'operator' => 'concat-assign',
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<link rel=\'stylesheet\' type=\'text/css\' href=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 97,
                        'char' => 69,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 97,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 97,
                      'char' => 75,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'themes/default/style.css\' />',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 97,
                      'char' => 105,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 97,
                    'char' => 105,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 97,
                  'char' => 105,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 99,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sources',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 99,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 100,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the css sources
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 89,
          'last-line' => 104,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getJsSources',
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
                  'variable' => 'uri',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 107,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'sources',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 107,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 109,
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
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 109,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 109,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 109,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 109,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 111,
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
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<script type=\'text/javascript\' src=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 111,
                        'char' => 61,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 111,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 111,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'bower_components/jquery/dist/jquery.min.js\'></script>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 111,
                      'char' => 122,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 111,
                    'char' => 122,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 111,
                  'char' => 122,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 112,
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
                  'operator' => 'concat-assign',
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<script type=\'text/javascript\' src=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 112,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 112,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 112,
                      'char' => 66,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'bower_components/jquery-ui/jquery-ui.min.js\'></script>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 112,
                      'char' => 122,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 112,
                    'char' => 122,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 112,
                  'char' => 122,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 113,
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
                  'operator' => 'concat-assign',
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<script type=\'text/javascript\' src=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 113,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 113,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 113,
                      'char' => 66,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'bower_components/jquery.scrollTo/jquery.scrollTo.min.js\'></script>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 113,
                      'char' => 134,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 113,
                    'char' => 134,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 113,
                  'char' => 134,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 114,
              'char' => 11,
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
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<script type=\'text/javascript\' src=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 114,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 114,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 114,
                      'char' => 66,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'prettify/prettify.js\'></script>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 114,
                      'char' => 99,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 114,
                    'char' => 99,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 114,
                  'char' => 99,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 115,
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
                  'operator' => 'concat-assign',
                  'variable' => 'sources',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<script type=\'text/javascript\' src=\'',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 115,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 115,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 115,
                      'char' => 66,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'pretty.js\'></script>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 115,
                      'char' => 88,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 115,
                    'char' => 88,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 115,
                  'char' => 88,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 117,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sources',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 117,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 118,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the javascript sources
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 106,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 106,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 105,
          'last-line' => 122,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getVersion',
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
                  'variable' => 'link',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 125,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 127,
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
                  'variable' => 'link',
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
                          'value' => 'action',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 128,
                          'char' => 19,
                        ),
                        'value' => 
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
                                  'value' => 'https://docs.phalconphp.com/',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 128,
                                  'char' => 50,
                                ),
                                'right' => 
                                array (
                                  'type' => 'scall',
                                  'dynamic-class' => 0,
                                  'class' => 'Version',
                                  'dynamic' => 0,
                                  'name' => 'getPart',
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'static-constant-access',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'Version',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 128,
                                          'char' => 91,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'VERSION_MAJOR',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 128,
                                          'char' => 91,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 128,
                                        'char' => 91,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 128,
                                      'char' => 91,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 128,
                                  'char' => 93,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 128,
                                'char' => 93,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '.',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 128,
                                'char' => 97,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 128,
                              'char' => 97,
                            ),
                            'right' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Version',
                              'dynamic' => 0,
                              'name' => 'getPart',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'static-constant-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'Version',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 128,
                                      'char' => 139,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'VERSION_MEDIUM',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 128,
                                      'char' => 139,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 128,
                                    'char' => 139,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 128,
                                  'char' => 139,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 128,
                              'char' => 141,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 128,
                            'char' => 141,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '/en/',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 128,
                            'char' => 147,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 128,
                          'char' => 147,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 128,
                        'char' => 147,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'text',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 129,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'Version',
                          'dynamic' => 0,
                          'name' => 'get',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 129,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 129,
                        'char' => 35,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'local',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 130,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 130,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 130,
                        'char' => 26,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'target',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 131,
                          'char' => 19,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => '_new',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 132,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 132,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 132,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 132,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 134,
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
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '<div class=\'version\'>Phalcon Framework ',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 134,
                    'char' => 56,
                  ),
                  'right' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Tag',
                    'dynamic' => 0,
                    'name' => 'linkTo',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'link',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 134,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 134,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 134,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 134,
                  'char' => 76,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '</div>',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 134,
                  'char' => 84,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 134,
                'char' => 84,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 135,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a link to the current version documentation
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 124,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 124,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 123,
          'last-line' => 139,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'halt',
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
                      'value' => 'Halted request',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 142,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 142,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 142,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Halts the request showing a backtrace
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 140,
          'last-line' => 147,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listen',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'exceptions',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 148,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 148,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'lowSeverity',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 148,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 148,
              'char' => 76,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'exceptions',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 150,
                'char' => 23,
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
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 151,
                      'char' => 18,
                    ),
                    'name' => 'listenExceptions',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 151,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 152,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 154,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'lowSeverity',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 154,
                'char' => 24,
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
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 155,
                      'char' => 18,
                    ),
                    'name' => 'listenLowSeverity',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 155,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 156,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 158,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 158,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Listen for uncaught exceptions and unsilent notices or warnings
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 149,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 149,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 149,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 148,
          'last-line' => 163,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listenExceptions',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'set_exception_handler',
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
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 167,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 167,
                          'char' => 18,
                        ),
                        1 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'string',
                            'value' => 'onUncaughtException',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 167,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 167,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 168,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 168,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 168,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 170,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 170,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 171,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Listen for uncaught exceptions
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 165,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 164,
          'last-line' => 175,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'listenLowSeverity',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'set_error_handler',
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
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 179,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 179,
                          'char' => 18,
                        ),
                        1 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'string',
                            'value' => 'onUncaughtLowSeverity',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 179,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 179,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 180,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 180,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 180,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 182,
              'char' => 29,
            ),
            1 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'set_exception_handler',
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
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 183,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 183,
                          'char' => 18,
                        ),
                        1 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'string',
                            'value' => 'onUncaughtException',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 183,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 183,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 184,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 184,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 184,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 186,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 186,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 187,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Listen for unsilent notices or warnings
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 177,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 177,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 177,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 176,
          'last-line' => 191,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'onUncaughtException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'exception',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\Exception',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 192,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 192,
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
                  'variable' => 'blacklist',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 194,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 194,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'dataVar',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 194,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'dataVars',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 194,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'escapedMessage',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 194,
                  'char' => 68,
                ),
                5 => 
                array (
                  'variable' => 'html',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 194,
                  'char' => 74,
                ),
                6 => 
                array (
                  'variable' => 'keyFile',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 195,
                  'char' => 20,
                ),
                7 => 
                array (
                  'variable' => 'keyRequest',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 195,
                  'char' => 32,
                ),
                8 => 
                array (
                  'variable' => 'keyServer',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 195,
                  'char' => 43,
                ),
                9 => 
                array (
                  'variable' => 'keyVar',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 195,
                  'char' => 51,
                ),
                10 => 
                array (
                  'variable' => 'n',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 195,
                  'char' => 54,
                ),
                11 => 
                array (
                  'variable' => 'showBackTrace',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 195,
                  'char' => 69,
                ),
                12 => 
                array (
                  'variable' => 'traceItem',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 195,
                  'char' => 80,
                ),
                13 => 
                array (
                  'variable' => 'obLevel',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 196,
                  'char' => 20,
                ),
                14 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 196,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
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
                  'variable' => 'obLevel',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'ob_get_level',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 198,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 198,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 203,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'obLevel',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 203,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 203,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 203,
                'char' => 24,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'ob_end_clean',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 204,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 205,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 210,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'static-property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'self',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 210,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'isActive',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 210,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 210,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'echo',
                  'expressions' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'exception',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 211,
                        'char' => 28,
                      ),
                      'name' => 'getMessage',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 211,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 213,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 214,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 219,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'isActive',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 219,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 219,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 221,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'className',
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
                          'value' => 'exception',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 221,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 221,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 221,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 221,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 226,
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
                  'variable' => 'escapedMessage',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 226,
                      'char' => 35,
                    ),
                    'name' => 'escapeString',
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
                            'value' => 'exception',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 227,
                            'char' => 23,
                          ),
                          'name' => 'getMessage',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 228,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 228,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 228,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 228,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 234,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'html',
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
                            'value' => '<html><head><title>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 234,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 234,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 234,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ': ',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 234,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 234,
                        'char' => 57,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'escapedMessage',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 234,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 234,
                      'char' => 74,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</title>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 234,
                      'char' => 84,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 234,
                    'char' => 84,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 234,
                  'char' => 84,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 235,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'html',
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
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 235,
                        'char' => 25,
                      ),
                      'name' => 'getCssSources',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 235,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</head><body>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 235,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 235,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 235,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 240,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'html',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 240,
                      'char' => 25,
                    ),
                    'name' => 'getVersion',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 240,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 240,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 245,
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
                  'operator' => 'concat-assign',
                  'variable' => 'html',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '<div align=\'center\'><div class=\'error-main\'>',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 245,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 245,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 246,
              'char' => 11,
            ),
            11 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'html',
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
                            'value' => '<h1>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 246,
                            'char' => 25,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 246,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 246,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ': ',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 246,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 246,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'escapedMessage',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 246,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 246,
                      'char' => 59,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</h1>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 246,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 246,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 246,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 247,
              'char' => 11,
            ),
            12 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'html',
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
                            'value' => '<span class=\'error-file\'>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 247,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'exception',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 247,
                              'char' => 58,
                            ),
                            'name' => 'getFile',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 247,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 247,
                          'char' => 69,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ' (',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 247,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 247,
                        'char' => 74,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'exception',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 247,
                          'char' => 86,
                        ),
                        'name' => 'getLine',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 247,
                        'char' => 97,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 247,
                      'char' => 97,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')</span>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 247,
                      'char' => 107,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 247,
                    'char' => 107,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 247,
                  'char' => 107,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 248,
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
                  'variable' => 'html',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '</div>',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 248,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 248,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 250,
              'char' => 11,
            ),
            14 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'showBackTrace',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 250,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'showBackTrace',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 250,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 250,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 250,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 255,
              'char' => 10,
            ),
            15 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'showBackTrace',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 255,
                'char' => 26,
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
                      'variable' => 'dataVars',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 256,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 256,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 256,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 256,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 261,
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
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<div class=\'error-info\'><div id=\'tabs\'><ul>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 261,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 261,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 262,
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
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<li><a href=\'#error-tabs-1\'>Backtrace</a></li>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 262,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 262,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 263,
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
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<li><a href=\'#error-tabs-2\'>Request</a></li>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 263,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 263,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 264,
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
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<li><a href=\'#error-tabs-3\'>Server</a></li>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 264,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 264,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 265,
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
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<li><a href=\'#error-tabs-4\'>Included Files</a></li>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 265,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 265,
                      'char' => 75,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 266,
                  'char' => 15,
                ),
                6 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<li><a href=\'#error-tabs-5\'>Memory</a></li>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 266,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 266,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 268,
                  'char' => 14,
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
                        'value' => 'dataVars',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 268,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 268,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 268,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 268,
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
                          'operator' => 'concat-assign',
                          'variable' => 'html',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '<li><a href=\'#error-tabs-6\'>Variables</a></li>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 269,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 269,
                          'char' => 74,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 270,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 272,
                  'char' => 15,
                ),
                8 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '</ul>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 272,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 272,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 277,
                  'char' => 15,
                ),
                9 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<div id=\'error-tabs-1\'><table cellspacing=\'0\' align=\'center\' width=\'100%\'>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 277,
                        'char' => 98,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 277,
                      'char' => 98,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 279,
                  'char' => 15,
                ),
                10 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'exception',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 279,
                      'char' => 43,
                    ),
                    'name' => 'getTrace',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 279,
                    'char' => 56,
                  ),
                  'key' => 'n',
                  'value' => 'traceItem',
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
                          'variable' => 'html',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 283,
                              'char' => 33,
                            ),
                            'name' => 'showTraceItem',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'n',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 283,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 283,
                                'char' => 49,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'traceItem',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 283,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 283,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 283,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 283,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 284,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 286,
                  'char' => 15,
                ),
                11 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '</table></div>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 286,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 286,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 291,
                  'char' => 15,
                ),
                12 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<div id=\'error-tabs-2\'><table cellspacing=\'0\' align=\'center\' class=\'superglobal-detail\'>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 291,
                        'char' => 112,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 291,
                      'char' => 112,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 292,
                  'char' => 15,
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
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<tr><th>Key</th><th>Value</th></tr>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 292,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 292,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 293,
                  'char' => 15,
                ),
                14 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'blacklist',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Arr',
                        'dynamic' => 0,
                        'name' => 'get',
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
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 293,
                                'char' => 43,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'blacklist',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 293,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 293,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 293,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'request',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 293,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 293,
                            'char' => 62,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'empty-array',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 293,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 293,
                            'char' => 66,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 293,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 293,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 295,
                  'char' => 15,
                ),
                15 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => '_REQUEST',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 295,
                    'char' => 47,
                  ),
                  'key' => 'keyRequest',
                  'value' => 'value',
                  'reverse' => 0,
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
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 296,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'list',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'blacklist',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 296,
                                'char' => 44,
                              ),
                              'right' => 
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
                                      'type' => 'variable',
                                      'value' => 'keyRequest',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 296,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 296,
                                    'char' => 66,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 296,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 296,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 296,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 296,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 296,
                        'char' => 70,
                      ),
                      'statements' => 
                      array (
                        0 => 
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
                                'value' => 'value',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 297,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 297,
                              'char' => 38,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 297,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 297,
                            'char' => 46,
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
                                  'variable' => 'html',
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
                                            'value' => '<tr><td class=\'key\'>',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 298,
                                            'char' => 57,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'keyRequest',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 298,
                                            'char' => 70,
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 298,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '</td><td>',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 298,
                                          'char' => 82,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 298,
                                        'char' => 82,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'value',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 298,
                                        'char' => 90,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 298,
                                      'char' => 90,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '</td></tr>',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 298,
                                      'char' => 102,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 298,
                                    'char' => 102,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 298,
                                  'char' => 102,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 299,
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
                                  'variable' => 'html',
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
                                            'value' => '<tr><td class=\'key\'>',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 300,
                                            'char' => 57,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'keyRequest',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 300,
                                            'char' => 70,
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 300,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '</td><td>',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 300,
                                          'char' => 82,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 300,
                                        'char' => 82,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'print_r',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'value',
                                              'file' => '/app/phalcon/Debug/Debug.zep',
                                              'line' => 300,
                                              'char' => 97,
                                            ),
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 300,
                                            'char' => 97,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'bool',
                                              'value' => 'true',
                                              'file' => '/app/phalcon/Debug/Debug.zep',
                                              'line' => 300,
                                              'char' => 103,
                                            ),
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 300,
                                            'char' => 103,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 300,
                                        'char' => 105,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 300,
                                      'char' => 105,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '</td></tr>',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 300,
                                      'char' => 117,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 300,
                                    'char' => 117,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 300,
                                  'char' => 117,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 301,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 302,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 303,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 305,
                  'char' => 15,
                ),
                16 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '</table></div>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 305,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 305,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 310,
                  'char' => 15,
                ),
                17 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<div id=\'error-tabs-3\'><table cellspacing=\'0\' align=\'center\' class=\'superglobal-detail\'>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 310,
                        'char' => 112,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 310,
                      'char' => 112,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 311,
                  'char' => 15,
                ),
                18 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<tr><th>Key</th><th>Value</th></tr>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 311,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 311,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 312,
                  'char' => 15,
                ),
                19 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'blacklist',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Arr',
                        'dynamic' => 0,
                        'name' => 'get',
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
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 312,
                                'char' => 43,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'blacklist',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 312,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 312,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 312,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'server',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 312,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 312,
                            'char' => 61,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'empty-array',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 312,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 312,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 312,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 312,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 314,
                  'char' => 15,
                ),
                20 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => '_SERVER',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 314,
                    'char' => 45,
                  ),
                  'key' => 'keyServer',
                  'value' => 'value',
                  'reverse' => 0,
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
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 315,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'list',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'blacklist',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 315,
                                'char' => 44,
                              ),
                              'right' => 
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
                                      'type' => 'variable',
                                      'value' => 'keyServer',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 315,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 315,
                                    'char' => 65,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 315,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 315,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 315,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 315,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 315,
                        'char' => 69,
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
                              'variable' => 'html',
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
                                        'value' => '<tr><td class=\'key\'>',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 316,
                                        'char' => 53,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'keyServer',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 316,
                                        'char' => 65,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 316,
                                      'char' => 65,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '</td><td>',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 316,
                                      'char' => 77,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 316,
                                    'char' => 77,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 316,
                                      'char' => 84,
                                    ),
                                    'name' => 'getVarDump',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'value',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 316,
                                          'char' => 101,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 316,
                                        'char' => 101,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 316,
                                    'char' => 103,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 316,
                                  'char' => 103,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '</td></tr>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 316,
                                  'char' => 115,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 316,
                                'char' => 115,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 316,
                              'char' => 115,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 317,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 318,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 320,
                  'char' => 15,
                ),
                21 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '</table></div>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 320,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 320,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 325,
                  'char' => 15,
                ),
                22 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<div id=\'error-tabs-4\'><table cellspacing=\'0\' align=\'center\' class=\'superglobal-detail\'>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 325,
                        'char' => 112,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 325,
                      'char' => 112,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 326,
                  'char' => 15,
                ),
                23 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<tr><th>#</th><th>Path</th></tr>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 326,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 326,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 328,
                  'char' => 15,
                ),
                24 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'get_included_files',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 328,
                    'char' => 56,
                  ),
                  'key' => 'keyFile',
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
                          'variable' => 'html',
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
                                    'value' => '<tr><td>',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 329,
                                    'char' => 37,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'keyFile',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 329,
                                    'char' => 47,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 329,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '</th><td>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 329,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 329,
                                'char' => 59,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 329,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 329,
                              'char' => 67,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '</td></tr>',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 329,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 329,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 329,
                          'char' => 79,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 330,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 332,
                  'char' => 15,
                ),
                25 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '</table></div>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 332,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 332,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 337,
                  'char' => 15,
                ),
                26 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '<div id=\'error-tabs-5\'><table cellspacing=\'0\' align=\'center\' class=\'superglobal-detail\'>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 337,
                        'char' => 112,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 337,
                      'char' => 112,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 338,
                  'char' => 15,
                ),
                27 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '<tr><th colspan=\'2\'>Memory</th></tr><tr><td>Usage</td><td>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 338,
                            'char' => 83,
                          ),
                          'right' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'memory_get_usage',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 338,
                                  'char' => 106,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 338,
                                'char' => 106,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 338,
                            'char' => 108,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 338,
                          'char' => 108,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '</td></tr>',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 338,
                          'char' => 120,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 338,
                        'char' => 120,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 338,
                      'char' => 120,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 339,
                  'char' => 15,
                ),
                28 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '</table></div>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 339,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 339,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 344,
                  'char' => 14,
                ),
                29 => 
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
                        'value' => 'dataVars',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 344,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 344,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 344,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 344,
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
                          'operator' => 'concat-assign',
                          'variable' => 'html',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '<div id=\'error-tabs-6\'><table cellspacing=\'0\' align=\'center\' class=\'superglobal-detail\'>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 345,
                            'char' => 116,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 345,
                          'char' => 116,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 346,
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
                          'variable' => 'html',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '<tr><th>Key</th><th>Value</th></tr>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 346,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 346,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 348,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'dataVars',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 348,
                        'char' => 49,
                      ),
                      'key' => 'keyVar',
                      'value' => 'dataVar',
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
                              'variable' => 'html',
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
                                        'value' => '<tr><td class=\'key\'>',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 349,
                                        'char' => 53,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'keyVar',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 349,
                                        'char' => 62,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 349,
                                      'char' => 62,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '</td><td>',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 349,
                                      'char' => 74,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 349,
                                    'char' => 74,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 349,
                                      'char' => 81,
                                    ),
                                    'name' => 'getVarDump',
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
                                            'value' => 'dataVar',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 349,
                                            'char' => 100,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'int',
                                            'value' => '0',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 349,
                                            'char' => 102,
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 349,
                                          'char' => 103,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 349,
                                        'char' => 103,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 349,
                                    'char' => 105,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 349,
                                  'char' => 105,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '</td></tr>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 349,
                                  'char' => 117,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 349,
                                'char' => 117,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 349,
                              'char' => 117,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 350,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 352,
                      'char' => 19,
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
                          'variable' => 'html',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '</table></div>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 352,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 352,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 353,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 355,
                  'char' => 15,
                ),
                30 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '</div>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 355,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 355,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 356,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 361,
              'char' => 11,
            ),
            16 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'html',
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
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 361,
                        'char' => 25,
                      ),
                      'name' => 'getJsSources',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 361,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</div></body></html>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 361,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 361,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 361,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 366,
              'char' => 12,
            ),
            17 => 
            array (
              'type' => 'echo',
              'expressions' => 
              array (
                0 => 
                array (
                  'type' => 'variable',
                  'value' => 'html',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 366,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 371,
              'char' => 11,
            ),
            18 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'static-property',
                  'operator' => 'assign',
                  'variable' => 'self',
                  'property' => 'isActive',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 371,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 371,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 373,
              'char' => 14,
            ),
            19 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 373,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 374,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Handles uncaught exceptions
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 193,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 193,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 192,
          'last-line' => 378,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'onUncaughtLowSeverity',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'severity',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 379,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 379,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 379,
              'char' => 66,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'line',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 379,
              'char' => 72,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 379,
              'char' => 81,
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
                  'type' => 'bitwise_and',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'error_reporting',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 381,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'severity',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 381,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 381,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 381,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'ErrorException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 382,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 382,
                        'char' => 45,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 382,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 382,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'severity',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 382,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 382,
                        'char' => 58,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 382,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 382,
                        'char' => 64,
                      ),
                      4 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'line',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 382,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 382,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 382,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 383,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 384,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Throws an exception when a notice or warning is raised
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 380,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 379,
          'last-line' => 388,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBlacklist',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'blacklist',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 389,
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
                  'variable' => 'area',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 391,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 391,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'subArray',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 391,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 391,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 393,
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
                  'variable' => 'area',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'blacklist',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 393,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 393,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'request',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 393,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 393,
                        'char' => 51,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 393,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 393,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 393,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 393,
                  'char' => 56,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'subArray',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 394,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 394,
                  'char' => 26,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 395,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 395,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 397,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'area',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 397,
                'char' => 27,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'value',
                      'expr' => 
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
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 398,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 398,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 398,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 398,
                      'char' => 52,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'subArray',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 399,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 399,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 399,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 400,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 402,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'result',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'request',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 402,
                      'char' => 27,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'subArray',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 402,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 402,
                  'char' => 39,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'area',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'blacklist',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 403,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 403,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'server',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 403,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 403,
                        'char' => 59,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 403,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 403,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 403,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 403,
                  'char' => 64,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'subArray',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 404,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 404,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 406,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'area',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 406,
                'char' => 27,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'value',
                      'expr' => 
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
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 407,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 407,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 407,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 407,
                      'char' => 52,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'subArray',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 408,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 408,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 408,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 409,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 411,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'result',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'server',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 411,
                      'char' => 26,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'subArray',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 411,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 411,
                  'char' => 38,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'blacklist',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'result',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 412,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 412,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 414,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 414,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 415,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if files the exception\'s backtrace must be showed
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 390,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 390,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 390,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 389,
          'last-line' => 419,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setShowBackTrace',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'showBackTrace',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 420,
              'char' => 56,
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
                  'property' => 'showBackTrace',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'showBackTrace',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 422,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 422,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 424,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 424,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 425,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if files the exception\'s backtrace must be showed
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 421,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 421,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 421,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 420,
          'last-line' => 430,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setShowFileFragment',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'showFileFragment',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 431,
              'char' => 62,
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
                  'property' => 'showFileFragment',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'showFileFragment',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 433,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 433,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 435,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 435,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 436,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if files must be completely opened and showed in the output
     * or just the fragment related to the exception
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 432,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 432,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 432,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 431,
          'last-line' => 440,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setShowFiles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'showFiles',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 441,
              'char' => 48,
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
                  'property' => 'showFiles',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'showFiles',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 443,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 443,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 445,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 445,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 446,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set if files part of the backtrace must be shown in the output
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 442,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 442,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 442,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 441,
          'last-line' => 450,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 451,
              'char' => 39,
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
                  'property' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'uri',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 453,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 453,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 455,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 455,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 456,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Change the base URI for static resources
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
                  'value' => 'Debug',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 452,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 452,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 452,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 451,
          'last-line' => 460,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'escapeString',
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
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 461,
              'char' => 46,
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 463,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 463,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 463,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 463,
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
                    'name' => 'htmlentities',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'str_replace',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '\\n',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 465,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 465,
                              'char' => 31,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '\\\\n',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 465,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 465,
                              'char' => 36,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 465,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 465,
                              'char' => 43,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 465,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 465,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'ENT_COMPAT',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 466,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 466,
                        'char' => 27,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'utf-8',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 468,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 468,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 468,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 469,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 471,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 471,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 472,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Escapes a string with htmlentities
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 462,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 462,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 461,
          'last-line' => 476,
          'char' => 22,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getArrayDump',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'argument',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 477,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'n',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 477,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 477,
              'char' => 59,
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
                  'variable' => 'numberArguments',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 479,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'dump',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 479,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'varDump',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 479,
                  'char' => 43,
                ),
                3 => 
                array (
                  'variable' => 'k',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 479,
                  'char' => 46,
                ),
                4 => 
                array (
                  'variable' => 'v',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 479,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 481,
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
                  'variable' => 'numberArguments',
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
                          'value' => 'argument',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 481,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 481,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 481,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 481,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 483,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'greater-equal',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'n',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 483,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '3',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 483,
                    'char' => 19,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 483,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'numberArguments',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 483,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 483,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 483,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 483,
                'char' => 42,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 484,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 485,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 487,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater-equal',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'numberArguments',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 487,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '10',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 487,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 487,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'numberArguments',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 488,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 489,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 491,
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
                  'variable' => 'dump',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 491,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 491,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 493,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'argument',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 493,
                'char' => 30,
              ),
              'key' => 'k',
              'value' => 'v',
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
                      'type' => 'variable',
                      'value' => 'v',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 494,
                      'char' => 19,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 494,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 494,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'varDump',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '(empty string)',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 495,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 495,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 496,
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
                        'type' => 'fcall',
                        'name' => 'is_scalar',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'v',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 496,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 496,
                            'char' => 33,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 496,
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
                              'variable' => 'varDump',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 497,
                                  'char' => 36,
                                ),
                                'name' => 'escapeString',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'v',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 497,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 497,
                                    'char' => 51,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 497,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 497,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 498,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 498,
                      'char' => 20,
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
                            'value' => 'v',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 498,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 498,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 498,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 498,
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
                              'variable' => 'varDump',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Array(',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 499,
                                    'char' => 38,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 499,
                                      'char' => 45,
                                    ),
                                    'name' => 'getArrayDump',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'v',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 499,
                                          'char' => 60,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 499,
                                        'char' => 60,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'add',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'n',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 499,
                                            'char' => 64,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'int',
                                            'value' => '1',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 499,
                                            'char' => 67,
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 499,
                                          'char' => 67,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 499,
                                        'char' => 67,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 499,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 499,
                                  'char' => 69,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ')',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 499,
                                  'char' => 72,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 499,
                                'char' => 72,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 499,
                              'char' => 72,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 500,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 500,
                      'char' => 20,
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
                            'value' => 'v',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 500,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 500,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 500,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 500,
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
                              'variable' => 'varDump',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Object(',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 501,
                                    'char' => 39,
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
                                          'value' => 'v',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 501,
                                          'char' => 52,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 501,
                                        'char' => 52,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 501,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 501,
                                  'char' => 54,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ')',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 501,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 501,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 501,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 502,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 502,
                      'char' => 20,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'v',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 502,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 502,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 502,
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
                              'variable' => 'varDump',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => 'null',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 503,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 503,
                              'char' => 35,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 504,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 504,
                      'char' => 18,
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
                          'variable' => 'varDump',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'v',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 505,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 505,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 506,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 508,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'dump',
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
                              'type' => 'string',
                              'value' => '[',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 508,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'k',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 508,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 508,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '] =&gt; ',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 508,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 508,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'varDump',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 508,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 508,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 508,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 509,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 511,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'join',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => ', ',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 511,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 511,
                    'char' => 23,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'dump',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 511,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 511,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 511,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 512,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Produces a recursive representation of an array
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 477,
                'char' => 71,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 478,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 478,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 477,
          'last-line' => 516,
          'char' => 22,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getVarDump',
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
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 517,
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
                  'variable' => 'className',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 519,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'dumpedObject',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 519,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 521,
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
                  'type' => 'variable',
                  'value' => 'variable',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 521,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 521,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 521,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'true',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 522,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 523,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 525,
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
                  'type' => 'variable',
                  'value' => 'variable',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 525,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 525,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 525,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'false',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 526,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 527,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 532,
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
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 532,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 532,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 532,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 532,
                'char' => 38,
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
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 533,
                      'char' => 25,
                    ),
                    'name' => 'escapeString',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'variable',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 533,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 533,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 533,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 534,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 539,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_scalar',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 539,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 539,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 539,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'variable',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 540,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 541,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 546,
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
                    'value' => 'variable',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 546,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 546,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 546,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 546,
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
                      'variable' => 'className',
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
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 547,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 547,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 547,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 547,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 553,
                  'char' => 14,
                ),
                1 => 
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
                          'value' => 'variable',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 553,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 553,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'dump',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 553,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 553,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 553,
                    'char' => 46,
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
                          'variable' => 'dumpedObject',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'variable',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 554,
                              'char' => 45,
                            ),
                            'name' => 'dump',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 554,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 554,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 560,
                      'char' => 22,
                    ),
                    1 => 
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'Object(',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 560,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'className',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 560,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 560,
                              'char' => 45,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ': ',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 560,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 560,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 560,
                              'char' => 57,
                            ),
                            'name' => 'getArrayDump',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'dumpedObject',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 560,
                                  'char' => 83,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 560,
                                'char' => 83,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 560,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 560,
                          'char' => 85,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 560,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 560,
                        'char' => 88,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 561,
                      'char' => 13,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'Object(',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 566,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 566,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 566,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 566,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 566,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 567,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 568,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 573,
              'char' => 10,
            ),
            6 => 
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
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 573,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 573,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 573,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 573,
                'char' => 37,
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
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'Array(',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 574,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 574,
                          'char' => 34,
                        ),
                        'name' => 'getArrayDump',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'variable',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 574,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 574,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 574,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 574,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => ')',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 574,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 574,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 575,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 580,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'variable',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 580,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 580,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 580,
                'char' => 30,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'null',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 581,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 582,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 587,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'gettype',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'variable',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 587,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 587,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 587,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 588,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Produces an string representation of a variable
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 518,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 518,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 517,
          'last-line' => 593,
          'char' => 22,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'showTraceItem',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'n',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 594,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'trace',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 594,
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
                  'variable' => 'className',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 596,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'prepareInternalClass',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 596,
                  'char' => 44,
                ),
                2 => 
                array (
                  'variable' => 'preparedFunctionName',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 596,
                  'char' => 66,
                ),
                3 => 
                array (
                  'variable' => 'html',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 596,
                  'char' => 72,
                ),
                4 => 
                array (
                  'variable' => 'classReflection',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 597,
                  'char' => 28,
                ),
                5 => 
                array (
                  'variable' => 'prepareUriClass',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 597,
                  'char' => 45,
                ),
                6 => 
                array (
                  'variable' => 'functionName',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 597,
                  'char' => 59,
                ),
                7 => 
                array (
                  'variable' => 'functionReflection',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 597,
                  'char' => 79,
                ),
                8 => 
                array (
                  'variable' => 'traceArgs',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 598,
                  'char' => 22,
                ),
                9 => 
                array (
                  'variable' => 'arguments',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 598,
                  'char' => 33,
                ),
                10 => 
                array (
                  'variable' => 'argument',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 598,
                  'char' => 43,
                ),
                11 => 
                array (
                  'variable' => 'filez',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 598,
                  'char' => 50,
                ),
                12 => 
                array (
                  'variable' => 'line',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 598,
                  'char' => 56,
                ),
                13 => 
                array (
                  'variable' => 'showFiles',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 598,
                  'char' => 67,
                ),
                14 => 
                array (
                  'variable' => 'lines',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 598,
                  'char' => 74,
                ),
                15 => 
                array (
                  'variable' => 'numberLines',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 599,
                  'char' => 24,
                ),
                16 => 
                array (
                  'variable' => 'showFileFragment',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 599,
                  'char' => 42,
                ),
                17 => 
                array (
                  'variable' => 'firstLine',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 599,
                  'char' => 53,
                ),
                18 => 
                array (
                  'variable' => 'lastLine',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 599,
                  'char' => 63,
                ),
                19 => 
                array (
                  'variable' => 'i',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 599,
                  'char' => 66,
                ),
                20 => 
                array (
                  'variable' => 'linePosition',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 599,
                  'char' => 80,
                ),
                21 => 
                array (
                  'variable' => 'currentLine',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 600,
                  'char' => 24,
                ),
                22 => 
                array (
                  'variable' => 'classNameWithLink',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 600,
                  'char' => 43,
                ),
                23 => 
                array (
                  'variable' => 'functionNameWithLink',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 600,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 605,
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
                  'variable' => 'html',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<tr><td align=\'right\' valign=\'top\' class=\'error-number\'>#',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 605,
                        'char' => 78,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'n',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 605,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 605,
                      'char' => 82,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</td><td>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 605,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 605,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 605,
                  'char' => 93,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 607,
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
                  'value' => 'className',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 607,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'trace',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 607,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'class',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 607,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 607,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 607,
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
                    'name' => 'preg_match',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/^Phalcon/',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 612,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 612,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 612,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 612,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 612,
                    'char' => 50,
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
                          'variable' => 'prepareUriClass',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\\\\',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 616,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 616,
                                'char' => 53,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '_',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 616,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 616,
                                'char' => 56,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 616,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 616,
                                'char' => 67,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 616,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 616,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 621,
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
                          'variable' => 'classNameWithLink',
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
                                    'value' => '<a target=\'_new\' href=\'https://docs.phalconphp.com/4.0/en/api/',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 621,
                                    'char' => 104,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'prepareUriClass',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 621,
                                    'char' => 122,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 621,
                                  'char' => 122,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\'>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 621,
                                  'char' => 127,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 621,
                                'char' => 127,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'className',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 621,
                                'char' => 139,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 621,
                              'char' => 139,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '</a>',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 621,
                              'char' => 145,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 621,
                            'char' => 145,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 621,
                          'char' => 145,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 622,
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
                          'variable' => 'classReflection',
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
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 623,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 623,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 623,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 623,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 628,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'classReflection',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 628,
                          'char' => 36,
                        ),
                        'name' => 'isInternal',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 628,
                        'char' => 50,
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
                              'variable' => 'prepareInternalClass',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'str_replace',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '_',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 630,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 630,
                                    'char' => 26,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '-',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 631,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 631,
                                    'char' => 26,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
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
                                            'type' => 'variable',
                                            'value' => 'className',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 632,
                                            'char' => 45,
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 632,
                                          'char' => 45,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 633,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 633,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 633,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 633,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 638,
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
                              'variable' => 'classNameWithLink',
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
                                        'value' => '<a target=\'_new\' href=\'https://secure.php.net/manual/en/class.',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 638,
                                        'char' => 108,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'prepareInternalClass',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 638,
                                        'char' => 131,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 638,
                                      'char' => 131,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '.php\'>',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 638,
                                      'char' => 140,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 638,
                                    'char' => 140,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'className',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 638,
                                    'char' => 152,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 638,
                                  'char' => 152,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '</a>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 638,
                                  'char' => 158,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 638,
                                'char' => 158,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 638,
                              'char' => 158,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 639,
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
                              'variable' => 'classNameWithLink',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'className',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 640,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 640,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 641,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 642,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 644,
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
                      'operator' => 'concat-assign',
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '<span class=\'error-class\'>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 644,
                            'char' => 51,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'classNameWithLink',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 644,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 644,
                          'char' => 71,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '</span>',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 644,
                          'char' => 80,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 644,
                        'char' => 80,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 644,
                      'char' => 80,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 649,
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
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'trace',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 649,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 649,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 649,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 649,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 650,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 655,
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
                  'variable' => 'functionName',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'trace',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 655,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'function',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 655,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 655,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 655,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 657,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'trace',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 657,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'class',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 657,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 657,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 657,
                'char' => 31,
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
                      'variable' => 'functionNameWithLink',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'functionName',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 658,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 658,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 659,
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
                    'type' => 'fcall',
                    'name' => 'function_exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'functionName',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 663,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 663,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 663,
                    'char' => 46,
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
                          'variable' => 'functionReflection',
                          'expr' => 
                          array (
                            'type' => 'new',
                            'class' => 'ReflectionFunction',
                            'dynamic' => 0,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'functionName',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 664,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 664,
                                'char' => 77,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 664,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 664,
                          'char' => 78,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 669,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'functionReflection',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 669,
                          'char' => 39,
                        ),
                        'name' => 'isInternal',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 669,
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
                              'operator' => 'assign',
                              'variable' => 'preparedFunctionName',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'str_replace',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '_',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 674,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 674,
                                    'char' => 26,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '-',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 675,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 675,
                                    'char' => 26,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'functionName',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 677,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 677,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 677,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 677,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 679,
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
                              'variable' => 'functionNameWithLink',
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
                                        'value' => '<a target=\'_new\' href=\'https://secure.php.net/manual/en/function.',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 679,
                                        'char' => 114,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'preparedFunctionName',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 679,
                                        'char' => 137,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 679,
                                      'char' => 137,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '.php\'>',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 679,
                                      'char' => 146,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 679,
                                    'char' => 146,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'functionName',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 679,
                                    'char' => 161,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 679,
                                  'char' => 161,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '</a>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 679,
                                  'char' => 167,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 679,
                                'char' => 167,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 679,
                              'char' => 167,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 680,
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
                              'variable' => 'functionNameWithLink',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'functionName',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 681,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 681,
                              'char' => 60,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 682,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 683,
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
                          'variable' => 'functionNameWithLink',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'functionName',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 684,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 684,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 685,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 686,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 688,
              'char' => 11,
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
                  'variable' => 'html',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<span class=\'error-function\'>',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 688,
                        'char' => 50,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'functionNameWithLink',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 688,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 688,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</span>',
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 688,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 688,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 688,
                  'char' => 82,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 693,
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
                  'value' => 'traceArgs',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 693,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'trace',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 693,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'args',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 693,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 693,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 693,
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
                      'variable' => 'arguments',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 694,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 694,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 696,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'traceArgs',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 696,
                    'char' => 39,
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
                          'variable' => 'arguments',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => '<span class=\'error-parameter\'>',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 701,
                                'char' => 66,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 701,
                                  'char' => 73,
                                ),
                                'name' => 'getVarDump',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'argument',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 701,
                                      'char' => 93,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 701,
                                    'char' => 93,
                                  ),
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 701,
                                'char' => 95,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 701,
                              'char' => 95,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '</span>',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 701,
                              'char' => 104,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 701,
                            'char' => 104,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 701,
                          'char' => 104,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 702,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 707,
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
                      'variable' => 'html',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '(',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 707,
                            'char' => 26,
                          ),
                          'right' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'join',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ', ',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 707,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 707,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'arguments',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 707,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 707,
                                'char' => 46,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 707,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 707,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 707,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 707,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 707,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 708,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 714,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'filez',
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 714,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'trace',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 714,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'file',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 714,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 714,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 714,
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
                      'variable' => 'line',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'trace',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 715,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'line',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 715,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 715,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 715,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 715,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 720,
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
                      'operator' => 'concat-assign',
                      'variable' => 'html',
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
                                'value' => '<br/><div class=\'error-file\'>',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 720,
                                'char' => 54,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'filez',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 720,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 720,
                              'char' => 62,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => ' (',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 720,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 720,
                            'char' => 67,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'line',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 720,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 720,
                          'char' => 74,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => ')</div>',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 720,
                          'char' => 83,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 720,
                        'char' => 83,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 720,
                      'char' => 83,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 722,
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
                      'operator' => 'assign',
                      'variable' => 'showFiles',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 722,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'showFiles',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 722,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 722,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 722,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 727,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'showFiles',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 727,
                    'char' => 26,
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
                          'variable' => 'lines',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'file',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filez',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 732,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 732,
                                'char' => 39,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 732,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 732,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 734,
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
                          'variable' => 'numberLines',
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
                                  'value' => 'lines',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 734,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 734,
                                'char' => 46,
                              ),
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 734,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 734,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 735,
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
                          'variable' => 'showFileFragment',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 735,
                              'char' => 45,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'showFileFragment',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 735,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 735,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 735,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 741,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'showFileFragment',
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 741,
                        'char' => 37,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'declare',
                          'data-type' => 'int',
                          'variables' => 
                          array (
                            0 => 
                            array (
                              'variable' => 'beforeLine',
                              'expr' => 
                              array (
                                'type' => 'sub',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'line',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 745,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '7',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 745,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 745,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 745,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 750,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'less',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'beforeLine',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 750,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 750,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 750,
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
                                  'variable' => 'firstLine',
                                  'expr' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 751,
                                    'char' => 42,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 751,
                                  'char' => 42,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 752,
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
                                  'variable' => 'firstLine',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'beforeLine',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 753,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 753,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 754,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 759,
                          'char' => 23,
                        ),
                        2 => 
                        array (
                          'type' => 'declare',
                          'data-type' => 'int',
                          'variables' => 
                          array (
                            0 => 
                            array (
                              'variable' => 'afterLine',
                              'expr' => 
                              array (
                                'type' => 'add',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'line',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 759,
                                  'char' => 42,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '5',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 759,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 759,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 759,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 764,
                          'char' => 22,
                        ),
                        3 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'greater',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'afterLine',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 764,
                              'char' => 34,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'numberLines',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 764,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 764,
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
                                  'operator' => 'assign',
                                  'variable' => 'lastLine',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'numberLines',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 765,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 765,
                                  'char' => 51,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 766,
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
                                  'variable' => 'lastLine',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'afterLine',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 767,
                                    'char' => 49,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 767,
                                  'char' => 49,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 768,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 770,
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
                              'variable' => 'html',
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
                                            'value' => '<pre class=\'prettyprint highlight:',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 770,
                                            'char' => 67,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'firstLine',
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 770,
                                            'char' => 79,
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 770,
                                          'char' => 79,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ':',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 770,
                                          'char' => 83,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 770,
                                        'char' => 83,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'line',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 770,
                                        'char' => 90,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 770,
                                      'char' => 90,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ' linenums:',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 770,
                                      'char' => 103,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 770,
                                    'char' => 103,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'firstLine',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 770,
                                    'char' => 115,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 770,
                                  'char' => 115,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '\'>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 770,
                                  'char' => 119,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 770,
                                'char' => 119,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 770,
                              'char' => 119,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 771,
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
                              'variable' => 'firstLine',
                              'expr' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 772,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 772,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 773,
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
                              'variable' => 'lastLine',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'numberLines',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 773,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 773,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 774,
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
                              'variable' => 'html',
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
                                        'value' => '<pre class=\'prettyprint highlight:',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 774,
                                        'char' => 67,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'firstLine',
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 774,
                                        'char' => 79,
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 774,
                                      'char' => 79,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ':',
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 774,
                                      'char' => 83,
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 774,
                                    'char' => 83,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'line',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 774,
                                    'char' => 90,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 774,
                                  'char' => 90,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' linenums error-scroll\'>',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 774,
                                  'char' => 116,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 774,
                                'char' => 116,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 774,
                              'char' => 116,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 775,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 777,
                      'char' => 19,
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
                          'variable' => 'i',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'firstLine',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 777,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 777,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 779,
                      'char' => 21,
                    ),
                    5 => 
                    array (
                      'type' => 'while',
                      'expr' => 
                      array (
                        'type' => 'less-equal',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'i',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 779,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'lastLine',
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 779,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Debug/Debug.zep',
                        'line' => 779,
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
                              'variable' => 'linePosition',
                              'expr' => 
                              array (
                                'type' => 'sub',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'i',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 783,
                                  'char' => 42,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 783,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 783,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 783,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 788,
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
                              'variable' => 'currentLine',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'lines',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 788,
                                  'char' => 44,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'linePosition',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 788,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 788,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 788,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 793,
                          'char' => 22,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'showFileFragment',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 793,
                            'char' => 41,
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
                                  'type' => 'variable',
                                  'value' => 'i',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 794,
                                  'char' => 31,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'firstLine',
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 794,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 794,
                                'char' => 43,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'if',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'preg_match',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '#\\\\*\\\\/#',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 795,
                                          'char' => 51,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 795,
                                        'char' => 51,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
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
                                                'value' => 'currentLine',
                                                'file' => '/app/phalcon/Debug/Debug.zep',
                                                'line' => 795,
                                                'char' => 70,
                                              ),
                                              'file' => '/app/phalcon/Debug/Debug.zep',
                                              'line' => 795,
                                              'char' => 70,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 795,
                                          'char' => 71,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 795,
                                        'char' => 71,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 795,
                                    'char' => 73,
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
                                          'variable' => 'currentLine',
                                          'expr' => 
                                          array (
                                            'type' => 'fcall',
                                            'name' => 'str_replace',
                                            'call-type' => 1,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => '* /',
                                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                                  'line' => 797,
                                                  'char' => 40,
                                                ),
                                                'file' => '/app/phalcon/Debug/Debug.zep',
                                                'line' => 797,
                                                'char' => 40,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'string',
                                                  'value' => ' ',
                                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                                  'line' => 798,
                                                  'char' => 38,
                                                ),
                                                'file' => '/app/phalcon/Debug/Debug.zep',
                                                'line' => 798,
                                                'char' => 38,
                                              ),
                                              2 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'currentLine',
                                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                                  'line' => 800,
                                                  'char' => 33,
                                                ),
                                                'file' => '/app/phalcon/Debug/Debug.zep',
                                                'line' => 800,
                                                'char' => 33,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Debug/Debug.zep',
                                            'line' => 800,
                                            'char' => 34,
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 800,
                                          'char' => 34,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Debug/Debug.zep',
                                      'line' => 801,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 802,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 803,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 809,
                          'char' => 22,
                        ),
                        3 => 
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
                                'value' => 'currentLine',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 809,
                                'char' => 37,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\\n',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 809,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 809,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'currentLine',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 809,
                                'char' => 58,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\\r\\n',
                                'file' => '/app/phalcon/Debug/Debug.zep',
                                'line' => 809,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 809,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 809,
                            'char' => 65,
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
                                  'variable' => 'html',
                                  'expr' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '&nbsp;\\n',
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 810,
                                    'char' => 44,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 810,
                                  'char' => 44,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 811,
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
                                  'variable' => 'html',
                                  'expr' => 
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
                                          'type' => 'fcall',
                                          'name' => 'str_replace',
                                          'call-type' => 1,
                                          'parameters' => 
                                          array (
                                            0 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'string',
                                                'value' => '\\t',
                                                'file' => '/app/phalcon/Debug/Debug.zep',
                                                'line' => 817,
                                                'char' => 43,
                                              ),
                                              'file' => '/app/phalcon/Debug/Debug.zep',
                                              'line' => 817,
                                              'char' => 43,
                                            ),
                                            1 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'string',
                                                'value' => '  ',
                                                'file' => '/app/phalcon/Debug/Debug.zep',
                                                'line' => 817,
                                                'char' => 47,
                                              ),
                                              'file' => '/app/phalcon/Debug/Debug.zep',
                                              'line' => 817,
                                              'char' => 47,
                                            ),
                                            2 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'currentLine',
                                                'file' => '/app/phalcon/Debug/Debug.zep',
                                                'line' => 817,
                                                'char' => 60,
                                              ),
                                              'file' => '/app/phalcon/Debug/Debug.zep',
                                              'line' => 817,
                                              'char' => 60,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 817,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 817,
                                        'char' => 61,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'constant',
                                          'value' => 'ENT_COMPAT',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 818,
                                          'char' => 39,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 818,
                                        'char' => 39,
                                      ),
                                      2 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'UTF-8',
                                          'file' => '/app/phalcon/Debug/Debug.zep',
                                          'line' => 820,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Debug/Debug.zep',
                                        'line' => 820,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Debug/Debug.zep',
                                    'line' => 820,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Debug/Debug.zep',
                                  'line' => 820,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 821,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 823,
                          'char' => 23,
                        ),
                        4 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'incr',
                              'variable' => 'i',
                              'file' => '/app/phalcon/Debug/Debug.zep',
                              'line' => 823,
                              'char' => 28,
                            ),
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 824,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 826,
                      'char' => 19,
                    ),
                    6 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'concat-assign',
                          'variable' => 'html',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '</pre>',
                            'file' => '/app/phalcon/Debug/Debug.zep',
                            'line' => 826,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Debug/Debug.zep',
                          'line' => 826,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Debug/Debug.zep',
                      'line' => 827,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 828,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 830,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'html',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '</td></tr>',
                    'file' => '/app/phalcon/Debug/Debug.zep',
                    'line' => 830,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Debug/Debug.zep',
                  'line' => 830,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 832,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'html',
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 832,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Debug/Debug.zep',
              'line' => 833,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Shows a backtrace item
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
                'file' => '/app/phalcon/Debug/Debug.zep',
                'line' => 595,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Debug/Debug.zep',
            'line' => 595,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Debug/Debug.zep',
          'line' => 594,
          'last-line' => 834,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Debug/Debug.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Debug/Debug.zep',
    'line' => 23,
    'char' => 5,
  ),
);