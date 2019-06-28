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
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
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
        'name' => 'Phalcon\\Helper\\Number',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 17,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 18,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
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
        'name' => 'Phalcon\\Helper\\Str',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 19,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Exception\\InvalidArgumentException',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 20,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 21,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Message\\Stream',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 21,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 22,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\StreamInterface',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 22,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 23,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\UploadedFileInterface',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 23,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 24,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'RuntimeException',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 24,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 28,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-7 UploadedFile
 *',
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 29,
    'char' => 5,
  ),
  11 => 
  array (
    'type' => 'class',
    'name' => 'UploadedFile',
    'abstract' => 0,
    'final' => 1,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'UploadedFileInterface',
        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
        'line' => 30,
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
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'alreadyMoved',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 36,
            'char' => 33,
          ),
          'docblock' => '**
     * If the file has already been moved, we hold that status here
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 49,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'clientFilename',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 50,
            'char' => 35,
          ),
          'docblock' => '**
     * Retrieve the filename sent by the client.
     *
     * Do not trust the value returned by this method. A client could send
     * a malicious filename with the intention to corrupt or hack your
     * application.
     *
     * Implementations SHOULD return the value stored in the \'name\' key of
     * the file in the $_FILES array.
     *
     * @var string | null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 50,
              'char' => 41,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 63,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'clientMediaType',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 64,
            'char' => 36,
          ),
          'docblock' => '**
     * Retrieve the media type sent by the client.
     *
     * Do not trust the value returned by this method. A client could send
     * a malicious media type with the intention to corrupt or hack your
     * application.
     *
     * Implementations SHOULD return the value stored in the \'type\' key of
     * the file in the $_FILES array.
     *
     * @var string | null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 64,
              'char' => 42,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 80,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'error',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 81,
            'char' => 23,
          ),
          'docblock' => '**
     * Retrieve the error associated with the uploaded file.
     *
     * The return value MUST be one of PHP\'s UPLOAD_ERR_XXX constants.
     *
     * If the file was uploaded successfully, this method MUST return
     * UPLOAD_ERR_OK.
     *
     * Implementations SHOULD return the value stored in the \'error\' key of
     * the file in the $_FILES array.
     *
     * @see http://php.net/manual/en/features.file-upload.errors.php
     *
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 81,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 87,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'fileName',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 88,
            'char' => 24,
          ),
          'docblock' => '**
     * If the stream is a string (file name) we store it here
     *
     * @var string
     *',
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 98,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'size',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 99,
            'char' => 25,
          ),
          'docblock' => '**
     * Retrieve the file size.
     *
     * Implementations SHOULD return the value stored in the \'size\' key of
     * the file in the $_FILES array if available, as PHP calculates this based
     * on the actual size transmitted.
     *
     * @var int | null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 99,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 105,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'stream',
          'docblock' => '**
     * Holds the stream/string for the uploaded file
     *
     * @var StreamInterface|string|null
     *',
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 116,
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
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 118,
              'char' => 19,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'size',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 119,
                'char' => 24,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 119,
              'char' => 24,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'error',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 120,
                'char' => 22,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 120,
              'char' => 22,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'clientFilename',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 121,
                'char' => 37,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 121,
              'char' => 37,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'clientMediaType',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 123,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 123,
              'char' => 5,
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
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 128,
                  'char' => 14,
                ),
                'name' => 'checkStream',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'stream',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 128,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 128,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'error',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 128,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 128,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 128,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 133,
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
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 133,
                  'char' => 14,
                ),
                'name' => 'checkError',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'error',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 133,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 133,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 133,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 135,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'size',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'size',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 135,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 135,
                  'char' => 41,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'clientFilename',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'clientFilename',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 136,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 136,
                  'char' => 51,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'clientMediaType',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'clientMediaType',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 137,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 137,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 138,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * UploadedFile constructor.
     *
     * @param StreamInterface|string|null $stream
     * @param int|null                    $size
     * @param int                         $error
     * @param string|null                 $clientFilename
     * @param string|null                 $clientMediaType
     *',
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 117,
          'last-line' => 155,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getStream',
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
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 158,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 158,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'error',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 158,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 158,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 158,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 158,
                'char' => 39,
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 160,
                            'char' => 22,
                          ),
                          'name' => 'getErrorDescription',
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
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 160,
                                  'char' => 48,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'error',
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 160,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 160,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 160,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 161,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 161,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 161,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 162,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 164,
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
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 164,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'alreadyMoved',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 164,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 164,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 164,
                'char' => 40,
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
                          'value' => 'The file has already been moved to the target location',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 167,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 167,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 167,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 168,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 170,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'instanceof',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 170,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'stream',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 170,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 170,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'StreamInterface',
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 170,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 170,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 170,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 170,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 170,
                'char' => 64,
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
                      'property' => 'stream',
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
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 171,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'fileName',
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 171,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 171,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 171,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 171,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 171,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 172,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 174,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 174,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'stream',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 174,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 174,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieve a stream representing the uploaded file.
     *
     * This method MUST return a StreamInterface instance, representing the
     * uploaded file. The purpose of this method is to allow utilizing native
     * PHP stream functionality to manipulate the file upload, such as
     * stream_copy_to_stream() (though the result will need to be decorated in
     * a native PHP stream wrapper to work with such functions).
     *
     * If the moveTo() method has been called previously, this method MUST
     * raise an exception.
     *
     * @return StreamInterface Stream representation of the uploaded file.
     * @throws RuntimeException in cases when no stream is available or can be
     *     created.
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
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 157,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 157,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 156,
          'last-line' => 210,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'moveTo',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'targetPath',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 211,
              'char' => 42,
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
                  'variable' => 'sapi',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 213,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 215,
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
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 215,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'alreadyMoved',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 215,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 215,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 215,
                'char' => 40,
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
                          'value' => 'File has already been moved',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 216,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 216,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 216,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 217,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 219,
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
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 219,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 219,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'error',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 219,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 219,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 219,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 219,
                'char' => 39,
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 221,
                            'char' => 22,
                          ),
                          'name' => 'getErrorDescription',
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
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 221,
                                  'char' => 48,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'error',
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 221,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 221,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 221,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 222,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 222,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 222,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 223,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 228,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
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
                                'value' => 'targetPath',
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 228,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 228,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'string',
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 228,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 228,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'not',
                            'left' => 
                            array (
                              'type' => 'empty',
                              'left' => 
                              array (
                                'type' => 'list',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'targetPath',
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 229,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 229,
                                'char' => 33,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 229,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 229,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 229,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'is_dir',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'dirname',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'targetPath',
                                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                      'line' => 230,
                                      'char' => 38,
                                    ),
                                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                    'line' => 230,
                                    'char' => 38,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 230,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 230,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 230,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 230,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'is_writable',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'dirname',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'targetPath',
                                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                    'line' => 231,
                                    'char' => 43,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 231,
                                  'char' => 43,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 231,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 231,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 231,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 231,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 231,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 231,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 231,
                'char' => 47,
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
                          'value' => 'Target folder is empty string, not a folder or not writable',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 234,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 234,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 234,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 235,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 237,
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
                  'variable' => 'sapi',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'constant',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'PHP_SAPI',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 237,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 237,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 237,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 237,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 239,
              'char' => 10,
            ),
            5 => 
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
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'list',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sapi',
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 239,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 239,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 239,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'empty',
                            'left' => 
                            array (
                              'type' => 'list',
                              'left' => 
                              array (
                                'type' => 'property-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 240,
                                  'char' => 24,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fileName',
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 240,
                                  'char' => 33,
                                ),
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 240,
                                'char' => 33,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 240,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 240,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 240,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 240,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'starts_with',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sapi',
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 241,
                              'char' => 28,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 241,
                            'char' => 28,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'cli',
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 241,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 241,
                            'char' => 33,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 241,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 241,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'starts_with',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sapi',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 242,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 242,
                          'char' => 28,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'phpdbg',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 242,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 242,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 242,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 242,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 242,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 242,
                'char' => 39,
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
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 243,
                      'char' => 18,
                    ),
                    'name' => 'storeFile',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'targetPath',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 243,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 243,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 243,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 245,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'move_uploaded_file',
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
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 245,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'fileName',
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 245,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 245,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 245,
                          'char' => 58,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'targetPath',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 245,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 245,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 245,
                      'char' => 72,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 245,
                    'char' => 72,
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
                              'value' => 'The file cannot be moved to the target folder',
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 248,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 248,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 248,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 249,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 250,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 252,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'alreadyMoved',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 252,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 252,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 253,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Move the uploaded file to a new location.
     *
     * Use this method as an alternative to move_uploaded_file(). This method is
     * guaranteed to work in both SAPI and non-SAPI environments.
     * Implementations must determine which environment they are in, and use the
     * appropriate method (move_uploaded_file(), rename(), or a stream
     * operation) to perform the operation.
     *
     * $targetPath may be an absolute path, or a relative path. If it is a
     * relative path, resolution should be the same as used by PHP\'s rename()
     * function.
     *
     * The original file or stream MUST be removed on completion.
     *
     * If this method is called more than once, any subsequent calls MUST raise
     * an exception.
     *
     * When used in an SAPI environment where $_FILES is populated, when writing
     * files via moveTo(), is_uploaded_file() and move_uploaded_file() SHOULD be
     * used to ensure permissions and upload status are verified correctly.
     *
     * If you wish to move to a stream, use getStream(), as SAPI operations
     * cannot guarantee writing to stream destinations.
     *
     * @see http://php.net/is_uploaded_file
     * @see http://php.net/move_uploaded_file
     *
     * @param string $targetPath Path to which to move the uploaded file.
     *
     * @throws InvalidArgumentException if the $targetPath specified is invalid.
     * @throws RuntimeException on any error during the move operation, or on
     *     the second or subsequent call to the method.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 212,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 211,
          'last-line' => 259,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkError',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'error',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 260,
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
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 262,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Number',
                    'dynamic' => 0,
                    'name' => 'between',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'error',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 262,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 262,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 262,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 262,
                        'char' => 54,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '8',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 262,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 262,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 262,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 262,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 262,
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
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Invalid error. Must be one of the UPLOAD_ERR_* constants',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 265,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 265,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 265,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 266,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 268,
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
                  'property' => 'error',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'error',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 268,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 268,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 269,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the passed error code and if not in the range throws an exception
     *
     * @param int $error
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 261,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 260,
          'last-line' => 276,
          'char' => 20,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkStream',
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
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 277,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'error',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 277,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 279,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'error',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 279,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 279,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 279,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 280,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 280,
                    'char' => 27,
                  ),
                  'clauses' => 
                  array (
                    0 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'list',
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
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 281,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 281,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 281,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 281,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 281,
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
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'fileName',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'stream',
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 282,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 282,
                              'char' => 48,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 283,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 284,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 284,
                      'char' => 20,
                    ),
                    1 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'list',
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
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 284,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 284,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'resource',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 284,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 284,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 284,
                        'char' => 50,
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
                              'property' => 'stream',
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
                                      'value' => 'stream',
                                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                      'line' => 285,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                    'line' => 285,
                                    'char' => 57,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 285,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 285,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 286,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 287,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 287,
                      'char' => 20,
                    ),
                    2 => 
                    array (
                      'type' => 'case',
                      'expr' => 
                      array (
                        'type' => 'list',
                        'left' => 
                        array (
                          'type' => 'instanceof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'stream',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 287,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'StreamInterface',
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 287,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 287,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 287,
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
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'stream',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'stream',
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 288,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 288,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 289,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 290,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 290,
                      'char' => 23,
                    ),
                    3 => 
                    array (
                      'type' => 'default',
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
                                  'value' => 'Invalid stream or file passed',
                                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                  'line' => 291,
                                  'char' => 85,
                                ),
                                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                                'line' => 291,
                                'char' => 85,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 291,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 292,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 292,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 293,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 294,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the passed error code and if not in the range throws an exception
     *
     * @param StreamInterface|resource|string $stream
     * @param int                             $error
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 278,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 277,
          'last-line' => 302,
          'char' => 20,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getErrorDescription',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'error',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 303,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'errors',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 305,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 307,
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
                  'variable' => 'errors',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 308,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'There is no error, the file uploaded with success.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 308,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 308,
                        'char' => 67,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 309,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'The uploaded file exceeds the upload_max_filesize directive in php.ini.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 309,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 309,
                        'char' => 88,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 310,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 310,
                          'char' => 107,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 310,
                        'char' => 107,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '3',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 311,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'The uploaded file was only partially uploaded.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 311,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 311,
                        'char' => 63,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '4',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 312,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'No file was uploaded.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 312,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 312,
                        'char' => 38,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '6',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 313,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'Missing a temporary folder.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 313,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 313,
                        'char' => 44,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '7',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 314,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'Failed to write file to disk.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 314,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 314,
                        'char' => 46,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '8',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 315,
                          'char' => 15,
                        ),
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'A PHP extension stopped the file upload.',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 316,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 316,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 316,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 316,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 318,
              'char' => 14,
            ),
            2 => 
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
                      'value' => 'errors',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 318,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 318,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'error',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 318,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 318,
                    'char' => 38,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Unknown upload error',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 318,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 318,
                    'char' => 60,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 318,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 319,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a description string depending on the upload error code passed
     *
     * @param int $error
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
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 304,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 304,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 303,
          'last-line' => 325,
          'char' => 20,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'storeFile',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'targetPath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 326,
              'char' => 49,
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
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 328,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'handle',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 328,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'stream',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 328,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 330,
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
                          'type' => 'variable',
                          'value' => 'targetPath',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 330,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 330,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'w+b',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 330,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 330,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 330,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 330,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 331,
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
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 331,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'handle',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 331,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 331,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 331,
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
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 332,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 332,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 332,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 333,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 335,
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
                  'variable' => 'stream',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 335,
                      'char' => 27,
                    ),
                    'name' => 'getStream',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 335,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 335,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 337,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'stream',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 337,
                  'char' => 16,
                ),
                'name' => 'rewind',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 337,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 339,
              'char' => 13,
            ),
            5 => 
            array (
              'type' => 'while',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 339,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'stream',
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 339,
                    'char' => 31,
                  ),
                  'name' => 'eof',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 339,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 339,
                'char' => 38,
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'stream',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 340,
                          'char' => 31,
                        ),
                        'name' => 'read',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '2048',
                              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                              'line' => 340,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                            'line' => 340,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 340,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 340,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 342,
                  'char' => 18,
                ),
                1 => 
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
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 342,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 342,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                          'line' => 342,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                        'line' => 342,
                        'char' => 32,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 342,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                  'line' => 343,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 345,
              'char' => 14,
            ),
            6 => 
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
                      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                      'line' => 345,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                    'line' => 345,
                    'char' => 22,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
                'line' => 345,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
              'line' => 346,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Store a file in the new location (stream)
     *
     * @param string $targetPath
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
            'line' => 327,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
          'line' => 326,
          'last-line' => 347,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
      'line' => 29,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFile.zep',
    'line' => 29,
    'char' => 11,
  ),
);