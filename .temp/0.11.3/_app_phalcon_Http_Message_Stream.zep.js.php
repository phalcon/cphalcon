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
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 *',
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 17,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Http/Message/Stream.zep',
        'line' => 17,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 18,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Exception',
        'file' => '/app/phalcon/Http/Message/Stream.zep',
        'line' => 18,
        'char' => 14,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 19,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\StreamInterface',
        'file' => '/app/phalcon/Http/Message/Stream.zep',
        'line' => 19,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 20,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'RuntimeException',
        'file' => '/app/phalcon/Http/Message/Stream.zep',
        'line' => 20,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 24,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-7 Stream
 *',
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 25,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Stream',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'StreamInterface',
        'file' => '/app/phalcon/Http/Message/Stream.zep',
        'line' => 26,
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
          'name' => 'handle',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 30,
            'char' => 28,
          ),
          'docblock' => '**
     * @var resource | null
     *',
          'file' => '/app/phalcon/Http/Message/Stream.zep',
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
          'name' => 'stream',
          'docblock' => '**
     * @var resource | string
     *',
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 39,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'warning',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 40,
            'char' => 30,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 47,
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
              'name' => 'stream',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 48,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'mode',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'rb',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 48,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 48,
              'char' => 62,
            ),
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 50,
                  'char' => 14,
                ),
                'name' => 'setStream',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'stream',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 50,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 50,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mode',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 50,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 50,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 50,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 51,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stream constructor.
     *
     * @param mixed  $stream
     * @param string $mode
     *',
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 48,
          'last-line' => 55,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__destruct',
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
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 58,
                  'char' => 14,
                ),
                'name' => 'close',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 58,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 59,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Closes the stream when the destructed.
     *',
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 56,
          'last-line' => 73,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__toString',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'try-catch',
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'likely',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 77,
                        'char' => 28,
                      ),
                      'name' => 'isReadable',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 77,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 77,
                    'char' => 42,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'likely',
                        'left' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 78,
                            'char' => 32,
                          ),
                          'name' => 'isSeekable',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 78,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 78,
                        'char' => 46,
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
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 79,
                              'char' => 26,
                            ),
                            'name' => 'rewind',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 79,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 80,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 82,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 82,
                          'char' => 29,
                        ),
                        'name' => 'getContents',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 82,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 83,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 86,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 86,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 87,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads all data from the stream into a string, from the beginning to end.
     *
     * This method MUST attempt to seek to the beginning of the stream before
     * reading data and read the stream until the end is reached.
     *
     * Warning: This could attempt to load a large amount of data into memory.
     *
     * This method MUST NOT raise an exception in order to conform with PHP\'s
     * string casting operations.
     *
     * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 75,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 75,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 74,
          'last-line' => 91,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'close',
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
                  'variable' => 'handle',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 94,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 96,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 96,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 96,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 96,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 96,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 96,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 96,
                'char' => 41,
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
                      'variable' => 'handle',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 97,
                          'char' => 31,
                        ),
                        'name' => 'detach',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 97,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 97,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 99,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'fclose',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handle',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 99,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 99,
                        'char' => 26,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 99,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 100,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 101,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Closes the stream and any underlying resources.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 93,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 92,
          'last-line' => 109,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'detach',
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
                  'variable' => 'handle',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 112,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 114,
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
                  'variable' => 'handle',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 114,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 114,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 114,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 114,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'handle',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 115,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 115,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 117,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'handle',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 117,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 118,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Separates any underlying resources from the stream.
     *
     * After the stream has been detached, the stream is in an unusable state.
     *
     * @return resource | null
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'resource',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 110,
                'char' => 42,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 110,
          'last-line' => 122,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'eof',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 125,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'handle',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 125,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 125,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 125,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'feof',
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
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 126,
                            'char' => 30,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 126,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 126,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 126,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 126,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 127,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 129,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 129,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 130,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true if the stream is at the end of the stream.
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 124,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 124,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 123,
          'last-line' => 134,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getContents',
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 137,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 139,
              'char' => 12,
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
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 139,
                  'char' => 14,
                ),
                'name' => 'checkHandle',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 139,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 140,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 140,
                  'char' => 14,
                ),
                'name' => 'checkReadable',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 140,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 142,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'stream_get_contents',
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
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 142,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 142,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 142,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 142,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 142,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 142,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 144,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 144,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 144,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 144,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 144,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Could not read from the file/stream',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 145,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 145,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 145,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 146,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 148,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 148,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 149,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the remaining contents in a string
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 136,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 136,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 135,
          'last-line' => 160,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMetadata',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 161,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 161,
              'char' => 47,
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
                  'variable' => 'metadata',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 163,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 165,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 165,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 165,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 165,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 165,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 165,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 165,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 166,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 167,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 169,
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
                  'variable' => 'metadata',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'stream_get_meta_data',
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
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 169,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 169,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 169,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 169,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 169,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 169,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 171,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 171,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 171,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 171,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 171,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'metadata',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 172,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 173,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 175,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Arr',
                'dynamic' => 0,
                'name' => 'get',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'metadata',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 175,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 175,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 175,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 175,
                    'char' => 38,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'empty-array',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 175,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 175,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 175,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 176,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get stream metadata as an associative array or retrieve a specific key.
     *
     * The keys returned are identical to the keys returned from PHP\'s
     * stream_get_meta_data() function.
     *
     * @param mixed|null $key
     *
     * @return array|mixed|null
     *',
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 161,
          'last-line' => 180,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSize',
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
                  'variable' => 'stats',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 183,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 185,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 185,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 185,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 185,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 185,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 185,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 185,
                'char' => 41,
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
                      'variable' => 'stats',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'fstat',
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
                                'file' => '/app/phalcon/Http/Message/Stream.zep',
                                'line' => 186,
                                'char' => 36,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'handle',
                                'file' => '/app/phalcon/Http/Message/Stream.zep',
                                'line' => 186,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 186,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 186,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 186,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 186,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 188,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'likely',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 188,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'stats',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 188,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 188,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 188,
                    'char' => 39,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Arr',
                        'dynamic' => 0,
                        'name' => 'get',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'stats',
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 189,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 189,
                            'char' => 38,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'size',
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 189,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 189,
                            'char' => 44,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 189,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 189,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 189,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 190,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 191,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 193,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 193,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 194,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the size of the stream if known.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 181,
                'char' => 39,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 182,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 182,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 181,
          'last-line' => 198,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isReadable',
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
                  'variable' => 'mode',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 201,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 203,
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
                  'variable' => 'mode',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 203,
                        'char' => 34,
                      ),
                      'name' => 'getMetadata',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'mode',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 203,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 203,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 203,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 203,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 203,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 205,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 205,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'strpbrk',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 205,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 205,
                      'char' => 38,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'r+',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 205,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 205,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 205,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 205,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 206,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns whether or not the stream is readable.
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 200,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 200,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 199,
          'last-line' => 210,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isSeekable',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'bool',
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 213,
                    'char' => 28,
                  ),
                  'name' => 'getMetadata',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'seekable',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 213,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 213,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 213,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 213,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 214,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns whether or not the stream is seekable.
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 212,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 212,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 211,
          'last-line' => 218,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isWritable',
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
                  'variable' => 'mode',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 221,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 223,
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
                  'variable' => 'mode',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 223,
                        'char' => 34,
                      ),
                      'name' => 'getMetadata',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'mode',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 223,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 223,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 223,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 223,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 223,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 225,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 225,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'strpbrk',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 225,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 225,
                      'char' => 38,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'xwca+',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 225,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 225,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 225,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 225,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 226,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns whether or not the stream is writable.
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 220,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 220,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 219,
          'last-line' => 234,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'read',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'length',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 235,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 237,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 239,
              'char' => 12,
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
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 239,
                  'char' => 14,
                ),
                'name' => 'checkHandle',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 239,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 240,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 240,
                  'char' => 14,
                ),
                'name' => 'checkReadable',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 240,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 242,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'fread',
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
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 242,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 242,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 242,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 242,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 242,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 242,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 242,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 242,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 244,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 244,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 244,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 244,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 244,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Could not read from the file/stream',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 245,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 245,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 245,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 246,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 248,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 248,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 249,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Read data from the stream.
     *
     * @param int $length
     *
     * @return string
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 236,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 236,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 235,
          'last-line' => 256,
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
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 259,
                  'char' => 14,
                ),
                'name' => 'seek',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 259,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 259,
                    'char' => 21,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 259,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 260,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Seek to the beginning of the stream.
     *
     * If the stream is not seekable, this method will raise an exception;
     * otherwise, it will perform a seek(0).
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 258,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 257,
          'last-line' => 267,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'seek',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 268,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'whence',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 268,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 268,
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
                  'variable' => 'seeker',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 270,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 272,
              'char' => 12,
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
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 272,
                  'char' => 14,
                ),
                'name' => 'checkHandle',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 272,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 273,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 273,
                  'char' => 14,
                ),
                'name' => 'checkSeekable',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 273,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 275,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'seeker',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'fseek',
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
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 275,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 275,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 275,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 275,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'offset',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 275,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 275,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'whence',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 275,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 275,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 275,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 275,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 277,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 277,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'seeker',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 277,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 277,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 277,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Could not seek on the file pointer',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 278,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 278,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 278,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 279,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 280,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Seek to a position in the stream.
     *
     * @param int $offset
     * @param int $whence
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 269,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 268,
          'last-line' => 287,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setStream',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'stream',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 288,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'mode',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'rb',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 288,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 288,
              'char' => 60,
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
                  'variable' => 'handle',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 290,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 292,
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
                  'variable' => 'handle',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'stream',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 292,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 292,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 293,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'stream',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 293,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 293,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 293,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 293,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 293,
                'char' => 44,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'set_error_handler',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'closure',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'type' => 'parameter',
                              'name' => 'error',
                              'const' => 0,
                              'data-type' => 'variable',
                              'mandatory' => 0,
                              'reference' => 0,
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 295,
                              'char' => 32,
                            ),
                          ),
                          'right' => 
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
                                  'property' => 'warning',
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                                    'line' => 296,
                                    'char' => 45,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                                  'line' => 296,
                                  'char' => 45,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 297,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 298,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 298,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 298,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 300,
                  'char' => 15,
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
                      'variable' => 'handle',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'fopen',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'stream',
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 300,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 300,
                            'char' => 38,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'mode',
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 300,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 300,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 300,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 300,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 302,
                  'char' => 33,
                ),
                2 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'restore_error_handler',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 302,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 303,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 305,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'or',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 305,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'warning',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 305,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 305,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 305,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 305,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'resource',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 305,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 305,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 305,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'stream',
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 305,
                        'char' => 78,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'get_resource_type',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'handle',
                              'file' => '/app/phalcon/Http/Message/Stream.zep',
                              'line' => 305,
                              'char' => 104,
                            ),
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 305,
                            'char' => 104,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 305,
                        'char' => 105,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 305,
                      'char' => 105,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 305,
                    'char' => 105,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 305,
                  'char' => 107,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 305,
                'char' => 107,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The stream provided is not valid (string/resource) or could not be opened.',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 308,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 308,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 308,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 309,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 311,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'handle',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'handle',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 311,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 311,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'stream',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'stream',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 312,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 312,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 313,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the stream - existing instance
     *
     * @param mixed  $stream
     * @param string $mode
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 289,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 295,
          'last-line' => 319,
          'char' => 24,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'tell',
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
                  'variable' => 'position',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 322,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 324,
              'char' => 12,
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
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 324,
                  'char' => 14,
                ),
                'name' => 'checkHandle',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 324,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 326,
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
                  'variable' => 'position',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'ftell',
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
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 326,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 326,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 326,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 326,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 326,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 326,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 328,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 328,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 328,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'int',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 328,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 328,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 328,
                'char' => 45,
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
                          'value' => 'Could not retrieve the pointer position',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 329,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 329,
                        'char' => 72,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 329,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 330,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 332,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'position',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 332,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 333,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current position of the file read/write pointer
     *
     * @return int
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 321,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 321,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 320,
          'last-line' => 341,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'write',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 342,
              'char' => 35,
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
                  'variable' => 'bytes',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 344,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 346,
              'char' => 12,
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
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 346,
                  'char' => 14,
                ),
                'name' => 'checkHandle',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 346,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 347,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 347,
                  'char' => 14,
                ),
                'name' => 'checkWritable',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 347,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 349,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'bytes',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'fwrite',
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
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 349,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream.zep',
                            'line' => 349,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 349,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 349,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 349,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 349,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 349,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 349,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 351,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 351,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'bytes',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 351,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 351,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 351,
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
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Could not write to the file/stream',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 352,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 352,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 352,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 353,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 355,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'bytes',
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 355,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 356,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Write data to the stream.
     *
     * @param string $data
     *
     * @return int
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
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 343,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 343,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 342,
          'last-line' => 360,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkHandle',
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 363,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 363,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 363,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 363,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 363,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 363,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'A valid resource is required.',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 364,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 364,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 364,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 365,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 366,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a handle is available and throws an exception otherwise
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 362,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 361,
          'last-line' => 370,
          'char' => 20,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkReadable',
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 373,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 373,
                      'char' => 35,
                    ),
                    'name' => 'isReadable',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 373,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 373,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 373,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The resource is not readable.',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 374,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 374,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 374,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 375,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 376,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a handle is readable and throws an exception otherwise
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 372,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 371,
          'last-line' => 380,
          'char' => 20,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkSeekable',
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 383,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 383,
                      'char' => 35,
                    ),
                    'name' => 'isSeekable',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 383,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 383,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 383,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The resource is not seekable.',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 384,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 384,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 384,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 385,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 386,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a handle is seekable and throws an exception otherwise
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 382,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 381,
          'last-line' => 390,
          'char' => 20,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkWritable',
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 393,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream.zep',
                      'line' => 393,
                      'char' => 35,
                    ),
                    'name' => 'isWritable',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 393,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 393,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Http/Message/Stream.zep',
                'line' => 393,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'RuntimeException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The resource is not writable.',
                          'file' => '/app/phalcon/Http/Message/Stream.zep',
                          'line' => 394,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream.zep',
                        'line' => 394,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream.zep',
                    'line' => 394,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream.zep',
                  'line' => 395,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream.zep',
              'line' => 396,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a handle is writeable and throws an exception otherwise
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/Stream.zep',
            'line' => 392,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream.zep',
          'line' => 391,
          'last-line' => 397,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/Stream.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Message/Stream.zep',
    'line' => 25,
    'char' => 5,
  ),
);