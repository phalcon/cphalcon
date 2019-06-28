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
    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\View\\Engine',
    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
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
        'name' => 'Phalcon\\Mvc\\View\\Engine\\AbstractEngine',
        'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
        'line' => 13,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Adapter to use PHP itself as templating engine
 *',
    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
    'line' => 18,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Php',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractEngine',
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
          'name' => 'render',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 23,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 23,
              'char' => 52,
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
                'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                'line' => 23,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 23,
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
                  'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                  'line' => 25,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                  'line' => 25,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 27,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'mustClean',
                'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                'line' => 27,
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
                    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                    'line' => 28,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                  'line' => 29,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 34,
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
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                    'line' => 34,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                  'line' => 34,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                  'line' => 34,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                'line' => 34,
                'char' => 35,
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
                    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                    'line' => 35,
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
                            'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                            'line' => 36,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                          'line' => 36,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                      'line' => 37,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                  'line' => 38,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 43,
              'char' => 15,
            ),
            3 => 
            array (
              'type' => 'require',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'path',
                'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                'line' => 43,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 45,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'mustClean',
                'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                'line' => 45,
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
                        'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                        'line' => 46,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'view',
                        'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                        'line' => 46,
                        'char' => 24,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                      'line' => 46,
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
                          'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                          'line' => 46,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                        'line' => 46,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                    'line' => 46,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
                  'line' => 47,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders a view using the template engine
     *',
          'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
          'line' => 23,
          'last-line' => 49,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Php.zep',
    'line' => 18,
    'char' => 5,
  ),
);