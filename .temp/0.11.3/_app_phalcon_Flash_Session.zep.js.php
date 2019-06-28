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
    'file' => '/app/phalcon/Flash/Session.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Flash',
    'file' => '/app/phalcon/Flash/Session.zep',
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
        'file' => '/app/phalcon/Flash/Session.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Flash/Session.zep',
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
        'name' => 'Phalcon\\Flash\\AbstractFlash',
        'file' => '/app/phalcon/Flash/Session.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Flash/Session.zep',
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
        'name' => 'Phalcon\\Flash\\Exception',
        'file' => '/app/phalcon/Flash/Session.zep',
        'line' => 15,
        'char' => 28,
      ),
    ),
    'file' => '/app/phalcon/Flash/Session.zep',
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
        'name' => 'Phalcon\\Session\\ManagerInterface',
        'alias' => 'SessionInterface',
        'file' => '/app/phalcon/Flash/Session.zep',
        'line' => 16,
        'char' => 57,
      ),
    ),
    'file' => '/app/phalcon/Flash/Session.zep',
    'line' => 21,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Temporarily stores the messages in session, then messages can be printed in
 * the next request
 *',
    'file' => '/app/phalcon/Flash/Session.zep',
    'line' => 22,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Session',
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
          'name' => 'clear',
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
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 29,
                  'char' => 14,
                ),
                'name' => 'getSessionMessages',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 29,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 29,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 29,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 30,
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
                'name' => 'clear',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 30,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 31,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Clear messages in the session messenger
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Flash/Session.zep',
            'line' => 28,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Session.zep',
          'line' => 27,
          'last-line' => 35,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 36,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 36,
              'char' => 44,
            ),
            1 => 
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
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 36,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 36,
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
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 38,
                  'char' => 21,
                ),
                'name' => 'getSessionMessages',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'remove',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 38,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 38,
                    'char' => 47,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 38,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 38,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 38,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the messages in the session flasher
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
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 37,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/Session.zep',
            'line' => 37,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Session.zep',
          'line' => 36,
          'last-line' => 43,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 44,
                'char' => 36,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 44,
              'char' => 36,
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
                  'variable' => 'messages',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 46,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 48,
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
                  'variable' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 48,
                      'char' => 29,
                    ),
                    'name' => 'getSessionMessages',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 48,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 48,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 48,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 48,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 50,
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
                    'value' => 'type',
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 50,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 50,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 50,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 50,
                'char' => 34,
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
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 51,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 52,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 54,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'messages',
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 54,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 54,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 54,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 54,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether there are messages
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
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 45,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/Session.zep',
            'line' => 45,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Session.zep',
          'line' => 44,
          'last-line' => 59,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 60,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 60,
              'char' => 56,
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
                  'variable' => 'messages',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 62,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 64,
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
                  'variable' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 64,
                      'char' => 29,
                    ),
                    'name' => 'getSessionMessages',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 64,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 64,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 64,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 64,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 66,
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
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 66,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 66,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 66,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 66,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 66,
                'char' => 34,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'messages',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 67,
                          'char' => 30,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 67,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 67,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 68,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 70,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index-append',
                  'operator' => 'assign',
                  'variable' => 'messages',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 70,
                      'char' => 26,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 70,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 70,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 72,
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
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 72,
                  'char' => 14,
                ),
                'name' => 'setSessionMessages',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 72,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 72,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 72,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a message to the session flasher
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Flash/Session.zep',
            'line' => 61,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Session.zep',
          'line' => 60,
          'last-line' => 77,
          'char' => 19,
        ),
        4 => 
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
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 78,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 78,
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
                  'variable' => 'type',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 80,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'message',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 80,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'messages',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 80,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 82,
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
                  'variable' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 82,
                      'char' => 29,
                    ),
                    'name' => 'getSessionMessages',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'remove',
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 82,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 82,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 82,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 82,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 84,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'messages',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 84,
                'char' => 39,
              ),
              'key' => 'type',
              'value' => 'message',
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
                      'value' => 'this',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 85,
                      'char' => 18,
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
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 85,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 85,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 85,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 85,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 85,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 86,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 88,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => 'clear',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 88,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 89,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prints the messages in the session flasher
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Flash/Session.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Session.zep',
          'line' => 78,
          'last-line' => 93,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getSessionMessages',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'remove',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 94,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 94,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 94,
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 96,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 96,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'messages',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 96,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'returnMessages',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 96,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 98,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 98,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 98,
                        'char' => 44,
                      ),
                      'name' => 'getDI',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 98,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 98,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 98,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 100,
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
                  'variable' => 'session',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'SessionInterface',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 100,
                      'char' => 71,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 100,
                        'char' => 52,
                      ),
                      'name' => 'getShared',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'session',
                            'file' => '/app/phalcon/Flash/Session.zep',
                            'line' => 100,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 100,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 100,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 100,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 100,
                  'char' => 71,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'session',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 101,
                      'char' => 32,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '_flashMessages',
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 101,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 101,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 101,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 101,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 106,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'messages',
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 106,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 106,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 106,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 106,
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
                      'variable' => 'messages',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 107,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 107,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 108,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 110,
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
                    'value' => 'type',
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 110,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 110,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 110,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 110,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'returnMessages',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 111,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'messages',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 111,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 111,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 111,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 111,
                    'char' => 53,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'remove',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 112,
                        'char' => 27,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'unset',
                          'expr' => 
                          array (
                            'type' => 'list',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'messages',
                                'file' => '/app/phalcon/Flash/Session.zep',
                                'line' => 113,
                                'char' => 35,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'type',
                                'file' => '/app/phalcon/Flash/Session.zep',
                                'line' => 113,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Flash/Session.zep',
                              'line' => 113,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Flash/Session.zep',
                            'line' => 113,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 114,
                          'char' => 27,
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
                              'value' => 'session',
                              'file' => '/app/phalcon/Flash/Session.zep',
                              'line' => 114,
                              'char' => 29,
                            ),
                            'name' => 'set',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '_flashMessages',
                                  'file' => '/app/phalcon/Flash/Session.zep',
                                  'line' => 114,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Flash/Session.zep',
                                'line' => 114,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'messages',
                                  'file' => '/app/phalcon/Flash/Session.zep',
                                  'line' => 114,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Flash/Session.zep',
                                'line' => 114,
                                'char' => 58,
                              ),
                            ),
                            'file' => '/app/phalcon/Flash/Session.zep',
                            'line' => 114,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 115,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 117,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'returnMessages',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 117,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 118,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 120,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 120,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 121,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 123,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'remove',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 123,
                'char' => 19,
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
                      'value' => 'session',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 124,
                      'char' => 21,
                    ),
                    'name' => 'remove',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '_flashMessages',
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 124,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 124,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 124,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 125,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 127,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'messages',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 127,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 128,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the messages stored in session
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
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 95,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/Session.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Session.zep',
          'line' => 94,
          'last-line' => 132,
          'char' => 22,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'setSessionMessages',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'messages',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 133,
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 135,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 135,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 137,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 137,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 137,
                        'char' => 44,
                      ),
                      'name' => 'getDI',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 137,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 137,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 137,
                  'char' => 52,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'session',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'SessionInterface',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 138,
                      'char' => 71,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Flash/Session.zep',
                        'line' => 138,
                        'char' => 52,
                      ),
                      'name' => 'getShared',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'session',
                            'file' => '/app/phalcon/Flash/Session.zep',
                            'line' => 138,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Flash/Session.zep',
                          'line' => 138,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 138,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 138,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 138,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 140,
              'char' => 15,
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
                  'value' => 'session',
                  'file' => '/app/phalcon/Flash/Session.zep',
                  'line' => 140,
                  'char' => 17,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '_flashMessages',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 140,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 140,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Flash/Session.zep',
                      'line' => 140,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Flash/Session.zep',
                    'line' => 140,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 140,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 142,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'messages',
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 142,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Flash/Session.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stores the messages in session
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
                'file' => '/app/phalcon/Flash/Session.zep',
                'line' => 134,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Flash/Session.zep',
            'line' => 134,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Flash/Session.zep',
          'line' => 133,
          'last-line' => 144,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Flash/Session.zep',
      'line' => 22,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Flash/Session.zep',
    'line' => 22,
    'char' => 5,
  ),
);