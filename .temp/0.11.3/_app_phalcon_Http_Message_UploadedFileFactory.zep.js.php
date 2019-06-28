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
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\UploadedFile',
        'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\StreamInterface',
        'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
        'line' => 18,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\UploadedFileInterface',
        'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
        'line' => 19,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\UploadedFileFactoryInterface',
        'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
        'line' => 20,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
    'line' => 24,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-17 UploadedFileFactory
 *',
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
    'line' => 25,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'UploadedFileFactory',
    'abstract' => 0,
    'final' => 1,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'UploadedFileFactoryInterface',
        'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
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
          'name' => 'createUploadedFile',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'stream',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'StreamInterface',
                'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                'line' => 46,
                'char' => 32,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
              'line' => 46,
              'char' => 33,
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
                'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                'line' => 47,
                'char' => 24,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
              'line' => 47,
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
                'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                'line' => 48,
                'char' => 22,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
              'line' => 48,
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
                'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                'line' => 49,
                'char' => 37,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
              'line' => 49,
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
                'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                'line' => 51,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
              'line' => 51,
              'char' => 5,
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
                'class' => 'UploadedFile',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'stream',
                      'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                      'line' => 54,
                      'char' => 19,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                    'line' => 54,
                    'char' => 19,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'size',
                      'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                      'line' => 55,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                    'line' => 55,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'error',
                      'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                      'line' => 56,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                    'line' => 56,
                    'char' => 18,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'clientFilename',
                      'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                      'line' => 57,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                    'line' => 57,
                    'char' => 27,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'clientMediaType',
                      'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                      'line' => 59,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                    'line' => 59,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                'line' => 59,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new uploaded file.
     *
     * If a size is not provided it will be determined by checking the size of
     * the stream.
     *
     * @link http://php.net/manual/features.file-upload.post-method.php
     * @link http://php.net/manual/features.file-upload.errors.php
     *
     * @param StreamInterface $stream          The underlying stream representing the
     *                                         uploaded file content.
     * @param int             $size            The size of the file in bytes.
     * @param int             $error           The PHP file upload error.
     * @param string          $clientFilename  The filename as provided by the client, if any.
     * @param string          $clientMediaType The media type as provided by the client, if any.
     *
     * @throws \\InvalidArgumentException If the file resource is not readable.
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
                  'value' => 'UploadedFileInterface',
                  'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                  'line' => 52,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
                'line' => 52,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
            'line' => 52,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
          'line' => 45,
          'last-line' => 61,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
      'line' => 25,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/UploadedFileFactory.zep',
    'line' => 25,
    'char' => 11,
  ),
);