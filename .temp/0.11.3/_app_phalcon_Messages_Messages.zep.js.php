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
    'file' => '/app/phalcon/Messages/Messages.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Messages',
    'file' => '/app/phalcon/Messages/Messages.zep',
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
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
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
        'name' => 'Countable',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 14,
        'char' => 14,
      ),
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
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
        'name' => 'Iterator',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 15,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
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
        'name' => 'JsonSerializable',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 16,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
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
        'name' => 'Phalcon\\Messages\\Message',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 17,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
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
        'name' => 'Phalcon\\Messages\\Exception',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 18,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Messages\\MessageInterface',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 19,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
    'line' => 23,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents a collection of messages
 *',
    'file' => '/app/phalcon/Messages/Messages.zep',
    'line' => 24,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Messages',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 24,
        'char' => 38,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'Countable',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 24,
        'char' => 49,
      ),
      2 => 
      array (
        'type' => 'variable',
        'value' => 'Iterator',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 24,
        'char' => 59,
      ),
      3 => 
      array (
        'type' => 'variable',
        'value' => 'JsonSerializable',
        'file' => '/app/phalcon/Messages/Messages.zep',
        'line' => 25,
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
          'name' => 'position',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 29,
            'char' => 27,
          ),
          'docblock' => '**
     * @var int
     *',
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 33,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'messages',
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 38,
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
              'name' => 'messages',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 39,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 39,
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
                  'property' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'messages',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 41,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 41,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 42,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Messages\\Messages constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 40,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 39,
          'last-line' => 52,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'appendMessage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'MessageInterface',
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 53,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 53,
              'char' => 61,
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
                  'property' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 55,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 55,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 56,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a message to the collection
     *
     *```php
     * $messages->appendMessage(
     *     new \\Phalcon\\Messages\\Message("This is a message")
     * );
     *```
     *',
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 53,
          'last-line' => 66,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'appendMessages',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'messages',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 67,
              'char' => 44,
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
                  'variable' => 'currentMessages',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 69,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'finalMessages',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 69,
                  'char' => 43,
                ),
                2 => 
                array (
                  'variable' => 'message',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 69,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 71,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 71,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 71,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 71,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 71,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 71,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 71,
                    'char' => 57,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 71,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 71,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 71,
                'char' => 66,
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
                          'value' => 'The messages must be array or object',
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 72,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 72,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 72,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 73,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 75,
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
                  'variable' => 'currentMessages',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 75,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 75,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 75,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 75,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 77,
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
                    'value' => 'messages',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 77,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 77,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 77,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 77,
                'char' => 37,
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
                        'value' => 'currentMessages',
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 81,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 81,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 81,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 81,
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
                          'variable' => 'finalMessages',
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
                                  'value' => 'currentMessages',
                                  'file' => '/app/phalcon/Messages/Messages.zep',
                                  'line' => 82,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Messages/Messages.zep',
                                'line' => 82,
                                'char' => 64,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'messages',
                                  'file' => '/app/phalcon/Messages/Messages.zep',
                                  'line' => 82,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Messages/Messages.zep',
                                'line' => 82,
                                'char' => 74,
                              ),
                            ),
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 82,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 82,
                          'char' => 75,
                        ),
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 83,
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
                          'variable' => 'finalMessages',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'messages',
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 84,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 84,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 85,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 87,
                  'char' => 15,
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
                      'property' => 'messages',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'finalMessages',
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 87,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 87,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 97,
                      'char' => 22,
                    ),
                    'name' => 'rewind',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 97,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 99,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'while',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 99,
                      'char' => 28,
                    ),
                    'name' => 'valid',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 99,
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
                              'value' => 'messages',
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 100,
                              'char' => 40,
                            ),
                            'name' => 'current',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 100,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 100,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 101,
                      'char' => 20,
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
                          'value' => 'this',
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 101,
                          'char' => 22,
                        ),
                        'name' => 'appendMessage',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'message',
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 101,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 101,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 101,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 102,
                      'char' => 24,
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
                          'value' => 'messages',
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 102,
                          'char' => 26,
                        ),
                        'name' => 'next',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 102,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 103,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 104,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends an array of messages to the collection
     *
     *```php
     * $messages->appendMessages($messagesArray);
     *```
     *
     * @param \\Phalcon\\Messages\\MessageInterface[] messages
     *',
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 67,
          'last-line' => 109,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'count',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 112,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'messages',
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 112,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 112,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 112,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 112,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 113,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the number of messages in the list
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 110,
          'last-line' => 117,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'current',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 120,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'messages',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 120,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 120,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 120,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'position',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 120,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 120,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 120,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 121,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current message in the iterator
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
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 119,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 119,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 119,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 118,
          'last-line' => 125,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'filter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'fieldName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 126,
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
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 128,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'messages',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 128,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'message',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 128,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 130,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 130,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 130,
                  'char' => 26,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 131,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 131,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 131,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 131,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 133,
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
                    'value' => 'messages',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 133,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 133,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 133,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 133,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'messages',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 138,
                    'char' => 37,
                  ),
                  'value' => 'message',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
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
                              'value' => 'message',
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 142,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 142,
                            'char' => 41,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'getField',
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 142,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 142,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 142,
                        'char' => 53,
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
                              'value' => 'fieldName',
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 143,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'message',
                                'file' => '/app/phalcon/Messages/Messages.zep',
                                'line' => 143,
                                'char' => 45,
                              ),
                              'name' => 'getField',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 143,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 143,
                            'char' => 57,
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
                                  'assign-type' => 'variable-append',
                                  'operator' => 'assign',
                                  'variable' => 'filtered',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'message',
                                    'file' => '/app/phalcon/Messages/Messages.zep',
                                    'line' => 144,
                                    'char' => 49,
                                  ),
                                  'file' => '/app/phalcon/Messages/Messages.zep',
                                  'line' => 144,
                                  'char' => 49,
                                ),
                              ),
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 145,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 146,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 147,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 148,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 150,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'filtered',
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 150,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 151,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Filters the message collection by field name
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
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 127,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 126,
          'last-line' => 161,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'jsonSerialize',
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
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 164,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 165,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'records',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 165,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 167,
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
                  'variable' => 'records',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 167,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 167,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 169,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 169,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'messages',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 169,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 169,
                'char' => 39,
              ),
              'value' => 'message',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 170,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 170,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 170,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 170,
                      'char' => 42,
                    ),
                    'right' => 
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
                            'value' => 'message',
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 170,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 170,
                          'char' => 65,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'jsonSerialize',
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 170,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 170,
                          'char' => 80,
                        ),
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 170,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 170,
                    'char' => 82,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'records',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'message',
                              'file' => '/app/phalcon/Messages/Messages.zep',
                              'line' => 171,
                              'char' => 41,
                            ),
                            'name' => 'jsonSerialize',
                            'call-type' => 3,
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 171,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 171,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 172,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'records',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'message',
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 173,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 173,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 174,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 175,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 177,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'records',
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 177,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 178,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns serialised message objects as array for json_encode. Calls
     * jsonSerialize on each object if present
     *
     *```php
     * $data = $messages->jsonSerialize();
     * echo json_encode($data);
     *```
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
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 163,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 162,
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
          'name' => 'key',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 185,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'position',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 185,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 185,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current position/key in the iterator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 184,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 184,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 183,
          'last-line' => 190,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'next',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-incr',
                  'variable' => 'this',
                  'property' => 'position',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 193,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 194,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Moves the internal iteration pointer to the next position
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 192,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 191,
          'last-line' => 206,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 207,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 209,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 209,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 209,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 209,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 209,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 209,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 210,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if an index exists
     *
     *```php
     * var_dump(
     *     isset($message["database"])
     * );
     *```
     *
     * @param int index
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
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 208,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 208,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 207,
          'last-line' => 220,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetGet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 221,
              'char' => 40,
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
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 223,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'returnValue',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 223,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 223,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 225,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'message',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 225,
                  'char' => 49,
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
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 225,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 225,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 225,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 225,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 225,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 225,
                'char' => 49,
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
                      'variable' => 'returnValue',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 226,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 226,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 227,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 229,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'returnValue',
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 229,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 230,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets an attribute a message using the array syntax
     *
     *```php
     * print_r(
     *     $messages[0]
     * );
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 222,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 222,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 221,
          'last-line' => 240,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetSet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 241,
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
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 241,
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
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 243,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 243,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 243,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 243,
                'char' => 37,
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
                          'value' => 'The message must be an object',
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 244,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 244,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 244,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 245,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 247,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'messages',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 247,
                      'char' => 33,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 247,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 247,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 248,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets an attribute using the array-syntax
     *
     *```php
     * $messages[0] = new \\Phalcon\\Messages\\Message("This is a message");
     *```
     *
     * @param \\Phalcon\\Messages\\Message message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 242,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 241,
          'last-line' => 256,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetUnset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 257,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 259,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 259,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 259,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 259,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 259,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 259,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_splice',
                    'call-type' => 1,
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
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 260,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'messages',
                            'file' => '/app/phalcon/Messages/Messages.zep',
                            'line' => 260,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 260,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 260,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 260,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 260,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Messages/Messages.zep',
                          'line' => 260,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Messages/Messages.zep',
                        'line' => 260,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 260,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 261,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 262,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes a message from the list
     *
     *```php
     * unset($message["database"]);
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 258,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 257,
          'last-line' => 266,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rewind',
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
                  'property' => 'position',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 269,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 269,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 270,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rewinds the internal iterator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 268,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 267,
          'last-line' => 274,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'valid',
          'statements' => 
          array (
            0 => 
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 277,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messages',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 277,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 277,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 277,
                      'char' => 42,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Messages/Messages.zep',
                      'line' => 277,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Messages/Messages.zep',
                    'line' => 277,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Messages/Messages.zep',
                  'line' => 277,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 277,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Messages/Messages.zep',
              'line' => 278,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if the current message in the iterator is valid
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
                'file' => '/app/phalcon/Messages/Messages.zep',
                'line' => 276,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Messages/Messages.zep',
            'line' => 276,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Messages/Messages.zep',
          'line' => 275,
          'last-line' => 279,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Messages/Messages.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Messages/Messages.zep',
    'line' => 24,
    'char' => 5,
  ),
);