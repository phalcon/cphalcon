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
    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html\\Helper',
    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
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
        'name' => 'Phalcon\\Html\\Exception',
        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
        'line' => 13,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
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
        'name' => 'Phalcon\\EscaperInterface',
        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Helper\\AbstractHelper
 *
 * Abstract class for all html helpers
 *',
    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
    'line' => 21,
    'char' => 8,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'AbstractHelper',
    'abstract' => 1,
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
          'name' => 'escaper',
          'docblock' => '**
     * @var <EscaperInterface>
     *',
          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
          'line' => 30,
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
              'name' => 'escaper',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'EscaperInterface',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 31,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 31,
              'char' => 59,
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
                  'property' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'escaper',
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 33,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 33,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 34,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
          'line' => 31,
          'last-line' => 38,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'renderFullElement',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 40,
              'char' => 19,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 41,
              'char' => 20,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 42,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 42,
              'char' => 30,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'raw',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 44,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 44,
              'char' => 5,
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
                  'variable' => 'content',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 46,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
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
                  'variable' => 'content',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'raw',
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 48,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 48,
                      'char' => 34,
                    ),
                    'extra' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 48,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'escaper',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 48,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 48,
                        'char' => 50,
                      ),
                      'name' => 'escapeHtml',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'text',
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 48,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 48,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 48,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 48,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 48,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 50,
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
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 50,
                          'char' => 21,
                        ),
                        'name' => 'renderElement',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tag',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 50,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 50,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'attributes',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 50,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 50,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 50,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'content',
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 50,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 50,
                      'char' => 63,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</',
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 50,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 50,
                    'char' => 68,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tag',
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 50,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 50,
                  'char' => 74,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '>',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 50,
                  'char' => 77,
                ),
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 50,
                'char' => 77,
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 51,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders an element
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
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 44,
                'char' => 17,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
            'line' => 44,
            'char' => 17,
          ),
          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
          'line' => 39,
          'last-line' => 55,
          'char' => 22,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'renderElement',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 56,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 56,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 56,
              'char' => 73,
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
                  'variable' => 'attrs',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 58,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'escapedAttrs',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 58,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 60,
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
                  'variable' => 'escapedAttrs',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 60,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 60,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 61,
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
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 61,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 61,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 61,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 61,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 61,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'attrs',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 62,
                          'char' => 37,
                        ),
                        'name' => 'orderAttributes',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'empty-array',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 62,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 62,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'attributes',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 62,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 62,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 62,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 62,
                      'char' => 69,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'escapedAttrs',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' ',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 63,
                          'char' => 34,
                        ),
                        'right' => 
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
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                  'line' => 63,
                                  'char' => 47,
                                ),
                                'name' => 'renderAttributes',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'attrs',
                                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                      'line' => 63,
                                      'char' => 70,
                                    ),
                                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                    'line' => 63,
                                    'char' => 70,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                'line' => 63,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 63,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 63,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 63,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 63,
                      'char' => 72,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 64,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 66,
              'char' => 14,
            ),
            3 => 
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
                      'type' => 'string',
                      'value' => '<',
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 66,
                      'char' => 18,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'tag',
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 66,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 66,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'escapedAttrs',
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 66,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 66,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '>',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 66,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 66,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 67,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders an element
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
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 57,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
            'line' => 57,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
          'line' => 56,
          'last-line' => 76,
          'char' => 22,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'orderAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'overrides',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 77,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 77,
              'char' => 73,
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
                  'variable' => 'intersect',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 79,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'order',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 79,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'results',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 79,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 81,
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
                  'variable' => 'order',
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
                          'value' => 'rel',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 82,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 82,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 82,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 83,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 83,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 83,
                        'char' => 26,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'for',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 84,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 84,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 84,
                        'char' => 26,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 85,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 85,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 85,
                        'char' => 26,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'href',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 86,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 86,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 86,
                        'char' => 26,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 87,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 87,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 87,
                        'char' => 26,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 88,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 88,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 88,
                        'char' => 26,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 89,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 89,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 89,
                        'char' => 26,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 90,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 90,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 90,
                        'char' => 26,
                      ),
                      9 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'class',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 91,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 92,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 92,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 92,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 92,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 94,
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
                  'variable' => 'intersect',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_intersect_key',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'order',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 94,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 94,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 94,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 94,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 94,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 94,
                  'char' => 63,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'results',
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
                          'value' => 'intersect',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 95,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 95,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 95,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 95,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 95,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 95,
                  'char' => 59,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'results',
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
                          'value' => 'overrides',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 96,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 96,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'results',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 96,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 96,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 96,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 96,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 101,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'results',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 101,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'escape',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 101,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 101,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 103,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'results',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 103,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Keeps all the attributes sorted - same order all the tome
     *
     * @param array overrides
     * @param array attributes
     *
     * @return array
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
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 78,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
            'line' => 78,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
          'line' => 77,
          'last-line' => 108,
          'char' => 22,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'renderAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 109,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 111,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 111,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 111,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 113,
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
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 113,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 113,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 114,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'attributes',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 114,
                'char' => 38,
              ),
              'key' => 'key',
              'value' => 'value',
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 115,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 115,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 115,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 115,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 115,
                        'char' => 48,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 115,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 115,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 115,
                    'char' => 56,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'or',
                          'left' => 
                          array (
                            'type' => 'identical',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                'line' => 116,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 116,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 116,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 116,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'identical',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                'line' => 117,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 117,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'resource',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 117,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 117,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 117,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 118,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 118,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 118,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 118,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 118,
                        'char' => 44,
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
                                          'value' => 'Value at index: \\"',
                                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                          'line' => 120,
                                          'char' => 44,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'key',
                                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                          'line' => 120,
                                          'char' => 50,
                                        ),
                                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                        'line' => 120,
                                        'char' => 50,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\" type: \\"',
                                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                        'line' => 120,
                                        'char' => 64,
                                      ),
                                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                      'line' => 120,
                                      'char' => 64,
                                    ),
                                    'right' => 
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
                                            'value' => 'value',
                                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                            'line' => 120,
                                            'char' => 79,
                                          ),
                                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                          'line' => 120,
                                          'char' => 79,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                      'line' => 120,
                                      'char' => 81,
                                    ),
                                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                    'line' => 120,
                                    'char' => 81,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\\" cannot be rendered',
                                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                    'line' => 121,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                  'line' => 121,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                'line' => 121,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 121,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 122,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 124,
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
                          'variable' => 'result',
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
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                  'line' => 124,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '=\\"',
                                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                  'line' => 124,
                                  'char' => 40,
                                ),
                                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                'line' => 124,
                                'char' => 40,
                              ),
                              'right' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'property-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                    'line' => 124,
                                    'char' => 47,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'escaper',
                                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                    'line' => 124,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                  'line' => 124,
                                  'char' => 56,
                                ),
                                'name' => 'escapeHtmlAttr',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                      'line' => 124,
                                      'char' => 77,
                                    ),
                                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                    'line' => 124,
                                    'char' => 77,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                'line' => 124,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 124,
                              'char' => 79,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\" ',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 124,
                              'char' => 84,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 124,
                            'char' => 84,
                          ),
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 124,
                          'char' => 84,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 125,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 126,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 128,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 128,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders all the attributes
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
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 110,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
            'line' => 110,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
          'line' => 109,
          'last-line' => 133,
          'char' => 22,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'selfClose',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 134,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 134,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 134,
              'char' => 69,
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
                  'variable' => 'attrs',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 136,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'escapedAttrs',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 136,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 138,
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
                  'variable' => 'escapedAttrs',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 138,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 138,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 139,
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
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 139,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 139,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 139,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 139,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 139,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'attrs',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 140,
                          'char' => 37,
                        ),
                        'name' => 'orderAttributes',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'empty-array',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 140,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 140,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'attributes',
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 140,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                            'line' => 140,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 140,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 140,
                      'char' => 69,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'escapedAttrs',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ' ',
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 141,
                          'char' => 34,
                        ),
                        'right' => 
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
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                  'line' => 141,
                                  'char' => 47,
                                ),
                                'name' => 'renderAttributes',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'attrs',
                                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                      'line' => 141,
                                      'char' => 70,
                                    ),
                                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                    'line' => 141,
                                    'char' => 70,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                                'line' => 141,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                              'line' => 141,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                          'line' => 141,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                        'line' => 141,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 141,
                      'char' => 72,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 142,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 144,
              'char' => 14,
            ),
            3 => 
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
                      'type' => 'string',
                      'value' => '<',
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 144,
                      'char' => 18,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'tag',
                      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                      'line' => 144,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 144,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'escapedAttrs',
                    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                    'line' => 144,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 144,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '/>',
                  'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                  'line' => 144,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 144,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
              'line' => 145,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Produces a self close tag i.e. <img />
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
                'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
          'line' => 134,
          'last-line' => 146,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
      'line' => 21,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Html/Helper/AbstractHelper.zep',
    'line' => 21,
    'char' => 14,
  ),
);