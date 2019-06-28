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
    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\View\\Engine\\Volt',
    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
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
        'name' => 'Phalcon\\Mvc\\View\\Exception',
        'alias' => 'BaseException',
        'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
        'line' => 13,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Class for exceptions thrown by Phalcon\\Mvc\\View
 *',
    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
    'line' => 18,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Exception',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'BaseException',
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
          'name' => 'statement',
          'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
          'line' => 22,
          'char' => 10,
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
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 22,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 22,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'statement',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 22,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 22,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 22,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 22,
              'char' => 86,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'previous',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\Exception',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 22,
                'char' => 108,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 22,
                'char' => 116,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 22,
              'char' => 116,
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
                  'property' => 'statement',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'statement',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                    'line' => 24,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                  'line' => 24,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 26,
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
                      'value' => 'message',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                      'line' => 26,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                    'line' => 26,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                      'line' => 26,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                    'line' => 26,
                    'char' => 42,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'previous',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                      'line' => 26,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                    'line' => 26,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 26,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 27,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
          'line' => 22,
          'last-line' => 31,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getStatement',
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
                  'variable' => 'statement',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                  'line' => 34,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 36,
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
                  'variable' => 'statement',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                      'line' => 36,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'statement',
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                      'line' => 36,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                    'line' => 36,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                  'line' => 36,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 38,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'statement',
                    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                    'line' => 38,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                  'line' => 38,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                  'line' => 38,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 38,
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
                      'variable' => 'statement',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                        'line' => 39,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                      'line' => 39,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                  'line' => 40,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 42,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'statement',
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 42,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
              'line' => 43,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets currently parsed statement (if any).
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
                'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
                'line' => 33,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
          'line' => 32,
          'last-line' => 44,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/View/Engine/Volt/Exception.zep',
    'line' => 18,
    'char' => 5,
  ),
);