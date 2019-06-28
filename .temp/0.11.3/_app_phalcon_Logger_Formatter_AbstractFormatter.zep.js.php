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
    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Formatter',
    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
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
        'name' => 'Phalcon\\Logger\\Logger',
        'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
    'line' => 15,
    'char' => 8,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'AbstractFormatter',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'FormatterInterface',
        'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
        'line' => 16,
        'char' => 1,
      ),
    ),
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
          'name' => 'interpolate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
              'line' => 24,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                'line' => 24,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
              'line' => 24,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 26,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 26,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
              'line' => 27,
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
                  'variable' => 'replace',
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 27,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
              'line' => 29,
              'char' => 10,
            ),
            2 => 
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
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                      'line' => 29,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                    'line' => 29,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                    'line' => 29,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 29,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'greater',
                  'left' => 
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
                          'value' => 'context',
                          'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                          'line' => 29,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                        'line' => 29,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                    'line' => 29,
                    'char' => 54,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                    'line' => 29,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 29,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                'line' => 29,
                'char' => 58,
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
                      'variable' => 'replace',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                        'line' => 30,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                      'line' => 30,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 32,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'context',
                    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                    'line' => 32,
                    'char' => 39,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'replace',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '{',
                                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                                  'line' => 33,
                                  'char' => 31,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                                  'line' => 33,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                                'line' => 33,
                                'char' => 37,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '}',
                                'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                                'line' => 33,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                              'line' => 33,
                              'char' => 40,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                            'line' => 33,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                          'line' => 33,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                      'line' => 34,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 36,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                          'line' => 36,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                        'line' => 36,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'replace',
                          'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                          'line' => 36,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                        'line' => 36,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                    'line' => 36,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                  'line' => 37,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
              'line' => 39,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'message',
                'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
                'line' => 39,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Interpolates context values into the message placeholders
     *
     * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
     * @param string $message
     * @param array $context
     *',
          'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
          'line' => 24,
          'last-line' => 41,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
      'line' => 15,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Logger/Formatter/AbstractFormatter.zep',
    'line' => 15,
    'char' => 14,
  ),
);