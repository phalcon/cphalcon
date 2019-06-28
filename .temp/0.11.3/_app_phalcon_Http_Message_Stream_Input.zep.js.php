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
    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message\\Stream',
    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Stream',
        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
    'line' => 25,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Describes a data stream from "php://input"
 *
 * Typically, an instance will wrap a PHP stream; this interface provides
 * a wrapper around the most common operations, including serialization of
 * the entire stream to a string.
 *',
    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
    'line' => 26,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Input',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Stream',
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'data',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
            'line' => 31,
            'char' => 20,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
          'line' => 35,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'eof',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
            'line' => 36,
            'char' => 24,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
          'line' => 40,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'php://input',
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 43,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 43,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'rb',
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 43,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 43,
                    'char' => 44,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 43,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 44,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Input constructor.
     *',
          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
          'line' => 41,
          'last-line' => 58,
          'char' => 19,
        ),
        1 => 
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
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 61,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eof',
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 61,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 61,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 61,
                'char' => 31,
              ),
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
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 62,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 62,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 62,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 63,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 65,
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
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 65,
                  'char' => 14,
                ),
                'name' => 'getContents',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 65,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 67,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 67,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'data',
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 67,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 67,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 68,
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
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 60,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
            'line' => 60,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
          'line' => 59,
          'last-line' => 79,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getContents',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'length',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '-1',
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 80,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 80,
              'char' => 48,
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
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 82,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 84,
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 84,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eof',
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 84,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 84,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 84,
                'char' => 31,
              ),
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
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 85,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 85,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 85,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 86,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 88,
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
                            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                            'line' => 88,
                            'char' => 51,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handle',
                            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                            'line' => 88,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                          'line' => 88,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 88,
                        'char' => 58,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                          'line' => 88,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 88,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 88,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 88,
                  'char' => 67,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 89,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 89,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 91,
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'int',
                        'value' => '-1',
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 91,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'length',
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 91,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 91,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 91,
                        'char' => 44,
                      ),
                      'name' => 'eof',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 91,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 91,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 91,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 91,
                'char' => 52,
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
                      'property' => 'eof',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 92,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 92,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 95,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 95,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'data',
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 95,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 95,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 96,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the remaining contents in a string
     *
     * @throws RuntimeException if unable to read.
     * @throws RuntimeException if error occurs while reading.
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
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 81,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
          'line' => 80,
          'last-line' => 100,
          'char' => 19,
        ),
        3 => 
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
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 103,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns whether or not the stream is writeable.
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
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 102,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
            'line' => 102,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
          'line' => 101,
          'last-line' => 112,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 113,
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
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 115,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 117,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'parent',
                    'dynamic' => 0,
                    'name' => 'read',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                          'line' => 117,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 117,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 117,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 117,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 119,
              'char' => 10,
            ),
            2 => 
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
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 119,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 119,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eof',
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 119,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 119,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 119,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 119,
                'char' => 40,
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
                      'property' => 'data',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 120,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 120,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 121,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 123,
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                    'line' => 123,
                    'char' => 26,
                  ),
                  'name' => 'eof',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 123,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 123,
                'char' => 33,
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
                      'property' => 'eof',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                        'line' => 124,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                      'line' => 124,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                  'line' => 125,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 127,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 127,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
              'line' => 128,
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
                'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
          'line' => 113,
          'last-line' => 129,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
      'line' => 26,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Message/Stream/Input.zep',
    'line' => 26,
    'char' => 5,
  ),
);