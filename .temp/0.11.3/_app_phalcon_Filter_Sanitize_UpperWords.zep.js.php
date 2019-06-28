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
    'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Filter\\Sanitize',
    'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
    'line' => 17,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Filter\\Sanitize\\UpperWords
 *
 * Sanitizes a value to uppercase teh first character of each word
 *',
    'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
    'line' => 18,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'UpperWords',
    'abstract' => 0,
    'final' => 0,
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
          'name' => '__invoke',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'input',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
              'line' => 23,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                  'line' => 25,
                  'char' => 19,
                ),
                'right' => 
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
                        'value' => 'mb_convert_case',
                        'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                        'line' => 25,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                      'line' => 25,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                  'line' => 25,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                'line' => 25,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_convert_case',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'input',
                          'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                          'line' => 26,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                        'line' => 26,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'MB_CASE_TITLE',
                          'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                          'line' => 26,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                        'line' => 26,
                        'char' => 56,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'UTF-8',
                          'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                          'line' => 26,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                        'line' => 26,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                    'line' => 26,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                  'line' => 27,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
              'line' => 29,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'ucwords',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'utf8_decode',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'input',
                            'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                            'line' => 29,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                          'line' => 29,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                      'line' => 29,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                    'line' => 29,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
                'line' => 29,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
              'line' => 30,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @var mixed input The text to sanitize
     *',
          'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
          'line' => 23,
          'last-line' => 31,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Filter/Sanitize/UpperWords.zep',
    'line' => 18,
    'char' => 5,
  ),
);