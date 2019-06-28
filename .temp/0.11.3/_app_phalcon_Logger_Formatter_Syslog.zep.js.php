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
    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Formatter',
    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
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
        'name' => 'Phalcon\\Logger\\Formatter\\AbstractFormatter',
        'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
        'line' => 13,
        'char' => 47,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
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
        'name' => 'Phalcon\\Logger\\Item',
        'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\Formatter\\Syslog
 *
 * Prepares a message to be used in a Syslog backend
 *',
    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
    'line' => 21,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Syslog',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractFormatter',
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
          'name' => 'format',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                'line' => 26,
                'char' => 38,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
              'line' => 26,
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
                  'variable' => 'context',
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 28,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'message',
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 28,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 28,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
              'line' => 30,
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
                  'variable' => 'message',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'item',
                      'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                      'line' => 30,
                      'char' => 28,
                    ),
                    'name' => 'getMessage',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                    'line' => 30,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 30,
                  'char' => 41,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'type',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'item',
                      'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                      'line' => 31,
                      'char' => 28,
                    ),
                    'name' => 'getType',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                    'line' => 31,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 31,
                  'char' => 38,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'context',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'item',
                      'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                      'line' => 32,
                      'char' => 28,
                    ),
                    'name' => 'getContext',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                    'line' => 32,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 32,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
              'line' => 34,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'context',
                    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                    'line' => 34,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 34,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 34,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                'line' => 34,
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
                      'variable' => 'message',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                          'line' => 35,
                          'char' => 32,
                        ),
                        'name' => 'interpolate',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'message',
                              'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                              'line' => 35,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                            'line' => 35,
                            'char' => 52,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'context',
                              'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                              'line' => 35,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                            'line' => 35,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                        'line' => 35,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                      'line' => 35,
                      'char' => 62,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                  'line' => 36,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
              'line' => 38,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
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
                      'value' => 'type',
                      'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                      'line' => 38,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                    'line' => 38,
                    'char' => 21,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'message',
                      'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                      'line' => 38,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                    'line' => 38,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                'line' => 38,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Applies a format to a message before sent it to the internal log
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
                'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
                'line' => 27,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
            'line' => 27,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
          'line' => 26,
          'last-line' => 40,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Formatter/Syslog.zep',
    'line' => 21,
    'char' => 5,
  ),
);