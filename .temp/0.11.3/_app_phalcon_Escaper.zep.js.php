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
    'file' => '/app/phalcon/Escaper.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Escaper.zep',
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
        'name' => 'Phalcon\\EscaperInterface',
        'file' => '/app/phalcon/Escaper.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Escaper.zep',
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
        'name' => 'Phalcon\\Escaper\\Exception',
        'file' => '/app/phalcon/Escaper.zep',
        'line' => 14,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Escaper.zep',
    'line' => 32,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you
 * may prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled
 * with UTF-8 support.
 *
 *```php
 * $escaper = new \\Phalcon\\Escaper();
 *
 * $escaped = $escaper->escapeCss("font-family: <Verdana>");
 *
 * echo $escaped; // font\\2D family\\3A \\20 \\3C Verdana\\3E
 *```
 *',
    'file' => '/app/phalcon/Escaper.zep',
    'line' => 33,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Escaper',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'EscaperInterface',
        'file' => '/app/phalcon/Escaper.zep',
        'line' => 34,
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
          'name' => 'doubleEncode',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 38,
            'char' => 34,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 42,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'encoding',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'utf-8',
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 43,
            'char' => 31,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 45,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'htmlEscapeMap',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 45,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 47,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'htmlQuoteType',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 47,
            'char' => 32,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 53,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'detectEncoding',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'str',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 54,
              'char' => 52,
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
                  'variable' => 'charset',
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 56,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 61,
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
                  'variable' => 'charset',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'phalcon_is_basic_charset',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'str',
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 61,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 61,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 61,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 61,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 63,
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
                    'value' => 'charset',
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 63,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 63,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 63,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 63,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'charset',
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 64,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 65,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 70,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'function_exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'mb_detect_encoding',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 70,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 70,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 70,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 70,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 71,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 72,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 78,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'UTF-32',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 78,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 78,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'UTF-8',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 78,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 78,
                    'char' => 38,
                  ),
                  2 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'ISO-8859-1',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 78,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 78,
                    'char' => 50,
                  ),
                  3 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'ASCII',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 78,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 78,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 78,
                'char' => 59,
              ),
              'value' => 'charset',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_detect_encoding',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'str',
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 79,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 79,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'charset',
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 79,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 79,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 79,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 79,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 79,
                    'char' => 55,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'charset',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 80,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 81,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 87,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'mb_detect_encoding',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'str',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 87,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 87,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 87,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 88,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Detect the character encoding of a string to be handled by an encoder.
     * Special-handling for chr(172) and chr(128) to chr(159) which fail to be
     * detected by mb_detect_encoding()
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 54,
                'char' => 64,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 55,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 55,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 54,
          'last-line' => 93,
          'char' => 25,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeCss',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'css',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 94,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'phalcon_escape_css',
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
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 101,
                        'char' => 18,
                      ),
                      'name' => 'normalizeEncoding',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'css',
                            'file' => '/app/phalcon/Escaper.zep',
                            'line' => 101,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 101,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 102,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 102,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 102,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Escape CSS strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 95,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 94,
          'last-line' => 108,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeJs',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'js',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 109,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'phalcon_escape_js',
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
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 116,
                        'char' => 18,
                      ),
                      'name' => 'normalizeEncoding',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'js',
                            'file' => '/app/phalcon/Escaper.zep',
                            'line' => 116,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 116,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 117,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 117,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 117,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 118,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Escape javascript strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 110,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 110,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 109,
          'last-line' => 122,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeHtml',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 123,
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
                'type' => 'fcall',
                'name' => 'htmlspecialchars',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'text',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 126,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 126,
                    'char' => 17,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 127,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'htmlQuoteType',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 127,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 127,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 127,
                    'char' => 32,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 128,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'encoding',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 128,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 128,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 128,
                    'char' => 27,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 129,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'doubleEncode',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 130,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 130,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 130,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 130,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 131,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Escapes a HTML string. Internally uses htmlspecialchars
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 124,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 124,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 123,
          'last-line' => 135,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeHtmlAttr',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 136,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'htmlspecialchars',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attribute',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 139,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 139,
                    'char' => 22,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'constant',
                      'value' => 'ENT_QUOTES',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 140,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 140,
                    'char' => 23,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 141,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'encoding',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 141,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 141,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 141,
                    'char' => 27,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 142,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'doubleEncode',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 143,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 143,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 143,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 143,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 144,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Escapes a HTML attribute string
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 137,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 137,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 136,
          'last-line' => 148,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeUrl',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'url',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 149,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'rawurlencode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'url',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 151,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 151,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 151,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 152,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Escapes a URL. Internally uses rawurlencode
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 150,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 150,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 149,
          'last-line' => 156,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEncoding',
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
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 159,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'encoding',
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 159,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 159,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 160,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal encoding used by the escaper
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 158,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 158,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 157,
          'last-line' => 164,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'normalizeEncoding',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'str',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 165,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'function_exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'mb_convert_encoding',
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 170,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 170,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 170,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 170,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 170,
                'char' => 59,
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
                          'value' => 'Extension \'mbstring\' is required',
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 171,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 171,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 171,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 172,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 178,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'mb_convert_encoding',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'str',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 179,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 179,
                    'char' => 16,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'UTF-32',
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 180,
                      'char' => 19,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 180,
                    'char' => 19,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Escaper.zep',
                        'line' => 181,
                        'char' => 18,
                      ),
                      'name' => 'detectEncoding',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'str',
                            'file' => '/app/phalcon/Escaper.zep',
                            'line' => 181,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Escaper.zep',
                          'line' => 181,
                          'char' => 37,
                        ),
                      ),
                      'file' => '/app/phalcon/Escaper.zep',
                      'line' => 182,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 182,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 182,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 183,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Utility to normalize a string\'s encoding to UTF-32.
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
                'file' => '/app/phalcon/Escaper.zep',
                'line' => 166,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 166,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 165,
          'last-line' => 191,
          'char' => 25,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDoubleEncode',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'doubleEncode',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 192,
              'char' => 54,
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
                  'property' => 'doubleEncode',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'doubleEncode',
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 194,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 194,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 195,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the double_encode to be used by the escaper
     *
     *```php
     * $escaper->setDoubleEncode(false);
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 193,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 192,
          'last-line' => 203,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setEncoding',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'encoding',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 204,
              'char' => 48,
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
                  'property' => 'encoding',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'encoding',
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 206,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 206,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 207,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the encoding to be used by the escaper
     *
     *```php
     * $escaper->setEncoding("utf-8");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 205,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 204,
          'last-line' => 215,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHtmlQuoteType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'quoteType',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 216,
              'char' => 51,
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
                  'property' => 'htmlQuoteType',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'quoteType',
                    'file' => '/app/phalcon/Escaper.zep',
                    'line' => 218,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Escaper.zep',
                  'line' => 218,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Escaper.zep',
              'line' => 219,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the HTML quoting type for htmlspecialchars
     *
     *```php
     * $escaper->setHtmlQuoteType(ENT_XHTML);
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Escaper.zep',
            'line' => 217,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Escaper.zep',
          'line' => 216,
          'last-line' => 220,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Escaper.zep',
      'line' => 33,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Escaper.zep',
    'line' => 33,
    'char' => 5,
  ),
);