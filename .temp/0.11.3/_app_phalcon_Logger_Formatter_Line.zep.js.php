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
    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Formatter',
    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
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
        'name' => 'Phalcon\\Logger\\Formatter\\Formatter',
        'file' => '/app/phalcon/Logger/Formatter/Line.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
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
        'file' => '/app/phalcon/Logger/Formatter/Line.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\Formatter\\Line
 *
 * Formats messages using an one-line string
 *',
    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
    'line' => 21,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Line',
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
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 28,
              'char' => 31,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 28,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
          'line' => 34,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'format',
          'docblock' => '**
     * Format applied to each message
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 35,
              'char' => 27,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 35,
              'char' => 33,
            ),
          ),
          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
          'line' => 39,
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
              'name' => 'format',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '[%date%][%type%] %message%',
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 40,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 40,
              'char' => 75,
            ),
            1 => 
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
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 40,
                'char' => 113,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 40,
              'char' => 113,
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
                  'property' => 'format',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'format',
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 42,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 42,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 43,
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
                  'property' => 'dateFormat',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'dateFormat',
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 43,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 43,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 44,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Logger\\Formatter\\Line construct
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
            'line' => 41,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
          'line' => 40,
          'last-line' => 48,
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
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 49,
                'char' => 38,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 49,
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
                  'variable' => 'format',
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 51,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 53,
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
                  'variable' => 'format',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 53,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'format',
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 53,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 53,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 53,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 58,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'memstr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'format',
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 58,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 58,
                    'char' => 25,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '%date%',
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 58,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 58,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 58,
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
                      'variable' => 'format',
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
                              'value' => '%date%',
                              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                              'line' => 60,
                              'char' => 23,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 60,
                            'char' => 23,
                          ),
                          1 => 
                          array (
                            'parameter' => 
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
                                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                      'line' => 62,
                                      'char' => 26,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'dateFormat',
                                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                      'line' => 62,
                                      'char' => 37,
                                    ),
                                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                    'line' => 62,
                                    'char' => 37,
                                  ),
                                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                  'line' => 62,
                                  'char' => 37,
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
                                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                      'line' => 63,
                                      'char' => 26,
                                    ),
                                    'name' => 'getTime',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                    'line' => 64,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                  'line' => 64,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                              'line' => 64,
                              'char' => 18,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 64,
                            'char' => 18,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'format',
                              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                              'line' => 66,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 66,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                        'line' => 66,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 66,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 67,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 72,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'memstr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'format',
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 72,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 72,
                    'char' => 25,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '%type%',
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 72,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 72,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 72,
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
                      'variable' => 'format',
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
                              'value' => '%type%',
                              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                              'line' => 73,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 73,
                            'char' => 44,
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
                                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                                'line' => 73,
                                'char' => 51,
                              ),
                              'name' => 'getName',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                              'line' => 73,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 73,
                            'char' => 61,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'format',
                              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                              'line' => 73,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 73,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                        'line' => 73,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 73,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 74,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 76,
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
                  'variable' => 'format',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
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
                            'value' => '%message%',
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 76,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                          'line' => 76,
                          'char' => 43,
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
                              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                              'line' => 76,
                              'char' => 50,
                            ),
                            'name' => 'getMessage',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 76,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                          'line' => 76,
                          'char' => 63,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'format',
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 76,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                          'line' => 76,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 76,
                      'char' => 73,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'PHP_EOL',
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 76,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 76,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 76,
                  'char' => 82,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 78,
              'char' => 10,
            ),
            5 => 
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
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 78,
                      'char' => 24,
                    ),
                    'name' => 'getContext',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 78,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 78,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 78,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 78,
                'char' => 48,
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
                      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                      'line' => 79,
                      'char' => 25,
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
                          'value' => 'format',
                          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                          'line' => 80,
                          'char' => 23,
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                        'line' => 80,
                        'char' => 23,
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
                            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                            'line' => 81,
                            'char' => 22,
                          ),
                          'name' => 'getContext',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                          'line' => 82,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                        'line' => 82,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                    'line' => 82,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                  'line' => 83,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 85,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'format',
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 85,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Logger/Formatter/Line.zep',
              'line' => 86,
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
                'file' => '/app/phalcon/Logger/Formatter/Line.zep',
                'line' => 50,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Formatter/Line.zep',
            'line' => 50,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Formatter/Line.zep',
          'line' => 49,
          'last-line' => 87,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Formatter/Line.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Formatter/Line.zep',
    'line' => 21,
    'char' => 5,
  ),
);