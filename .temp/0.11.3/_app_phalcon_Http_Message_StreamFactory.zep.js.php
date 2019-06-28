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
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
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
        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Exception\\InvalidArgumentException',
        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
        'line' => 18,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\StreamFactoryInterface',
        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
        'line' => 19,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\StreamInterface',
        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
        'line' => 20,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
    'line' => 24,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-17 StreamFactory
 *',
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
    'line' => 25,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'StreamFactory',
    'abstract' => 0,
    'final' => 1,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'StreamFactoryInterface',
        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
        'line' => 26,
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
          'name' => 'createStream',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 36,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 36,
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
                  'variable' => 'handle',
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 38,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 40,
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
                    'type' => 'fcall',
                    'name' => 'fopen',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'php://temp',
                          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                          'line' => 40,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 40,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'r+b',
                          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                          'line' => 40,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 40,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 40,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 40,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 41,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 41,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'handle',
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 41,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 41,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 41,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Cannot write to file.',
                          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                          'line' => 42,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 42,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 42,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 43,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 45,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'fcall',
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
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 45,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 45,
                    'char' => 22,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'content',
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 45,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 45,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 45,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 46,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'rewind',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 46,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 46,
                    'char' => 22,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 46,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 48,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 48,
                  'char' => 21,
                ),
                'name' => 'createStreamFromResource',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 48,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 48,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 48,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 49,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new stream from a string.
     *
     * The stream SHOULD be created with a temporary resource.
     *
     * @param string $content String content with which to populate the stream.
     *
     * @return StreamInterface
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
                  'value' => 'StreamInterface',
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 37,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 37,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
            'line' => 37,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
          'line' => 36,
          'last-line' => 65,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createStreamFromFile',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filename',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 66,
              'char' => 58,
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
                'value' => 'r+b',
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 66,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 66,
              'char' => 78,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Stream',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filename',
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 68,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 68,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mode',
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 68,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 68,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 68,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 69,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a stream from an existing file.
     *
     * The file MUST be opened using the given mode, which may be any mode
     * supported by the `fopen` function.
     *
     * The `$filename` MAY be any string supported by `fopen()`.
     *
     * @param string $filename The filename or stream URI to use as basis of
     *                         stream.
     * @param string $mode     The mode with which to open the underlying
     *                         filename/stream.
     *
     * @return StreamInterface
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
                  'value' => 'StreamInterface',
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 67,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
          'line' => 66,
          'last-line' => 75,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'createStreamFromResource',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'phpResource',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 76,
              'char' => 61,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'phpResource',
                          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                          'line' => 78,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 78,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'resource',
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 78,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 78,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'stream',
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 79,
                        'char' => 21,
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
                              'value' => 'phpResource',
                              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                              'line' => 79,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                            'line' => 79,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 79,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 79,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 79,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 79,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 79,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Invalid stream provided',
                          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                          'line' => 80,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                        'line' => 80,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 80,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 81,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 83,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Stream',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'phpResource',
                      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                      'line' => 83,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                    'line' => 83,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 83,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new stream from an existing resource.
     *
     * The stream MUST be readable and may be writable.
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
                  'value' => 'StreamInterface',
                  'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                  'line' => 77,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
                'line' => 77,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
            'line' => 77,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
          'line' => 76,
          'last-line' => 85,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
      'line' => 25,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/StreamFactory.zep',
    'line' => 25,
    'char' => 11,
  ),
);