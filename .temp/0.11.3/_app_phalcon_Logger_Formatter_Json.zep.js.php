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
    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Formatter',
    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
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
        'file' => '/app/phalcon/Logger/Formatter/Json.zep',
        'line' => 13,
        'char' => 47,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
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
        'file' => '/app/phalcon/Logger/Formatter/Json.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\Formatter\\Json
 *
 * Formats messages using JSON encoding
 *',
    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
    'line' => 21,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Json',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractFormatter',
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
          'name' => 'dateFormat',
          'docblock' => '**
     * Default date format
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 28,
              'char' => 31,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 28,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Logger/Formatter/Json.zep',
          'line' => 32,
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
              'name' => 'dateFormat',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'D, d M y H:i:s O',
                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                'line' => 33,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 33,
              'char' => 69,
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
                  'property' => 'dateFormat',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'dateFormat',
                    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                    'line' => 35,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 35,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 36,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Logger\\Formatter\\Json construct
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Formatter/Json.zep',
            'line' => 34,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Formatter/Json.zep',
          'line' => 33,
          'last-line' => 40,
          'char' => 19,
        ),
        1 => 
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
                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                'line' => 41,
                'char' => 38,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 41,
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
                  'variable' => 'message',
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 43,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 45,
              'char' => 10,
            ),
            1 => 
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
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'item',
                      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                      'line' => 45,
                      'char' => 24,
                    ),
                    'name' => 'getContext',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                    'line' => 45,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 45,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 45,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                'line' => 45,
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
                      'variable' => 'message',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                          'line' => 46,
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
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'item',
                                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                'line' => 47,
                                'char' => 22,
                              ),
                              'name' => 'getMessage',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 47,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                            'line' => 47,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'item',
                                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                'line' => 48,
                                'char' => 22,
                              ),
                              'name' => 'getContext',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 49,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                            'line' => 49,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                        'line' => 49,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                      'line' => 49,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 50,
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
                      'variable' => 'message',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'item',
                          'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                          'line' => 51,
                          'char' => 32,
                        ),
                        'name' => 'getMessage',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                        'line' => 51,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                      'line' => 51,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 52,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 54,
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
                  'type' => 'fcall',
                  'name' => 'json_encode',
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
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'type',
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 56,
                              'char' => 27,
                            ),
                            'value' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'item',
                                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                'line' => 56,
                                'char' => 34,
                              ),
                              'name' => 'getName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 56,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                            'line' => 56,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'message',
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 57,
                              'char' => 27,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'message',
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 57,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                            'line' => 57,
                            'char' => 36,
                          ),
                          2 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'timestamp',
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 58,
                              'char' => 27,
                            ),
                            'value' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'date',
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
                                      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                      'line' => 58,
                                      'char' => 39,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'dateFormat',
                                      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                      'line' => 58,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                    'line' => 58,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                  'line' => 58,
                                  'char' => 50,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'item',
                                      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                      'line' => 58,
                                      'char' => 57,
                                    ),
                                    'name' => 'getTime',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                    'line' => 58,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                                  'line' => 58,
                                  'char' => 67,
                                ),
                              ),
                              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                              'line' => 59,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                            'line' => 59,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                        'line' => 60,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                      'line' => 60,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 60,
                  'char' => 11,
                ),
                'right' => 
                array (
                  'type' => 'constant',
                  'value' => 'PHP_EOL',
                  'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                  'line' => 60,
                  'char' => 20,
                ),
                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                'line' => 60,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Formatter/Json.zep',
              'line' => 61,
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Logger/Formatter/Json.zep',
                'line' => 42,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Formatter/Json.zep',
            'line' => 42,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Formatter/Json.zep',
          'line' => 41,
          'last-line' => 62,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Formatter/Json.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Formatter/Json.zep',
    'line' => 21,
    'char' => 5,
  ),
);