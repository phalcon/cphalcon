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
    'file' => '/app/phalcon/Flash/Direct.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Flash',
    'file' => '/app/phalcon/Flash/Direct.zep',
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
        'name' => 'Phalcon\\Flash\\AbstractFlash',
        'file' => '/app/phalcon/Flash/Direct.zep',
        'line' => 13,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Flash/Direct.zep',
    'line' => 18,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This is a variant of the Phalcon\\Flash that immediately outputs any message
 * passed to it
 *',
    'file' => '/app/phalcon/Flash/Direct.zep',
    'line' => 19,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Direct',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractFlash',
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
          'name' => 'message',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Direct.zep',
              'line' => 24,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Direct.zep',
              'line' => 24,
              'char' => 53,
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
                  'file' => '/app/phalcon/Flash/Direct.zep',
                  'line' => 26,
                  'char' => 21,
                ),
                'name' => 'outputMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Flash/Direct.zep',
                      'line' => 26,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Flash/Direct.zep',
                    'line' => 26,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'message',
                      'file' => '/app/phalcon/Flash/Direct.zep',
                      'line' => 26,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Flash/Direct.zep',
                    'line' => 26,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Flash/Direct.zep',
                'line' => 26,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Flash/Direct.zep',
              'line' => 27,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Outputs a message
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
                'file' => '/app/phalcon/Flash/Direct.zep',
                'line' => 25,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/Direct.zep',
            'line' => 25,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Direct.zep',
          'line' => 24,
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
          'name' => 'output',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'remove',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Flash/Direct.zep',
                'line' => 32,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Direct.zep',
              'line' => 32,
              'char' => 46,
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
                  'variable' => 'message',
                  'file' => '/app/phalcon/Flash/Direct.zep',
                  'line' => 34,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Flash/Direct.zep',
              'line' => 36,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Flash/Direct.zep',
                  'line' => 36,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'messages',
                  'file' => '/app/phalcon/Flash/Direct.zep',
                  'line' => 36,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Flash/Direct.zep',
                'line' => 36,
                'char' => 39,
              ),
              'value' => 'message',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'echo',
                  'expressions' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'message',
                      'file' => '/app/phalcon/Flash/Direct.zep',
                      'line' => 37,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Flash/Direct.zep',
                  'line' => 38,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Direct.zep',
              'line' => 40,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'remove',
                'file' => '/app/phalcon/Flash/Direct.zep',
                'line' => 40,
                'char' => 19,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'scall',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'parent',
                    'dynamic' => 0,
                    'name' => 'clear',
                    'file' => '/app/phalcon/Flash/Direct.zep',
                    'line' => 41,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Flash/Direct.zep',
                  'line' => 42,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Direct.zep',
              'line' => 43,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prints the messages accumulated in the flasher
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Flash/Direct.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Direct.zep',
          'line' => 32,
          'last-line' => 44,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Flash/Direct.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Flash/Direct.zep',
    'line' => 19,
    'char' => 5,
  ),
);