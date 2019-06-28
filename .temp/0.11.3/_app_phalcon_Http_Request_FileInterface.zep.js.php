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
    'file' => '/app/phalcon/Http/Request/FileInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Request',
    'file' => '/app/phalcon/Http/Request/FileInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Http\\Request\\FileInterface
 *
 * Interface for Phalcon\\Http\\Request\\File
 *
 *',
    'file' => '/app/phalcon/Http/Request/FileInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'FileInterface',
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
          'name' => 'getName',
          'docblock' => '**
     * Returns the real name of the uploaded file
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
                'file' => '/app/phalcon/Http/Request/FileInterface.zep',
                'line' => 24,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/FileInterface.zep',
            'line' => 24,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Http/Request/FileInterface.zep',
          'line' => 24,
          'last-line' => 28,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRealType',
          'docblock' => '**
     * Gets the real mime type of the upload file using finfo
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
                'file' => '/app/phalcon/Http/Request/FileInterface.zep',
                'line' => 29,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/FileInterface.zep',
            'line' => 29,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Http/Request/FileInterface.zep',
          'line' => 29,
          'last-line' => 33,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSize',
          'docblock' => '**
     * Returns the file size of the uploaded file
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
                'file' => '/app/phalcon/Http/Request/FileInterface.zep',
                'line' => 34,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/FileInterface.zep',
            'line' => 34,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Http/Request/FileInterface.zep',
          'line' => 34,
          'last-line' => 38,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTempName',
          'docblock' => '**
     * Returns the temporal name of the uploaded file
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
                'file' => '/app/phalcon/Http/Request/FileInterface.zep',
                'line' => 39,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/FileInterface.zep',
            'line' => 39,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Http/Request/FileInterface.zep',
          'line' => 39,
          'last-line' => 44,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'docblock' => '**
     * Returns the mime type reported by the browser
     * This mime type is not completely secure, use getRealType() instead
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
                'file' => '/app/phalcon/Http/Request/FileInterface.zep',
                'line' => 45,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/FileInterface.zep',
            'line' => 45,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Http/Request/FileInterface.zep',
          'line' => 45,
          'last-line' => 49,
          'char' => 19,
        ),
        5 => 
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
              'name' => 'destination',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request/FileInterface.zep',
              'line' => 50,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Move the temporary file to a destination
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
                'file' => '/app/phalcon/Http/Request/FileInterface.zep',
                'line' => 50,
                'char' => 56,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/FileInterface.zep',
            'line' => 50,
            'char' => 56,
          ),
          'file' => '/app/phalcon/Http/Request/FileInterface.zep',
          'line' => 50,
          'last-line' => 51,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Request/FileInterface.zep',
      'line' => 51,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Http/Request/FileInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);