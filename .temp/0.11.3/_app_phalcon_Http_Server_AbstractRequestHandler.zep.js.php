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
    'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Server',
    'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
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
        'name' => 'Psr\\Http\\Message\\ResponseInterface',
        'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
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
        'name' => 'Psr\\Http\\Message\\ServerRequestInterface',
        'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Server\\RequestHandlerInterface',
        'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
        'line' => 15,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
    'line' => 22,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Handles a server request and produces a response.
 *
 * An HTTP request handler process an HTTP request in order to produce an
 * HTTP response.
 *',
    'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
    'line' => 23,
    'char' => 8,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'AbstractRequestHandler',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RequestHandlerInterface',
        'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
        'line' => 24,
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
            0 => 'abstract',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'handle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'request',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ServerRequestInterface',
                'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
                'line' => 30,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
              'line' => 30,
              'char' => 69,
            ),
          ),
          'docblock' => '**
     * Handles a request and produces a response.
     *
     * May call other collaborating code to generate the response.
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
                  'value' => 'ResponseInterface',
                  'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
                  'line' => 30,
                  'char' => 93,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
                'line' => 30,
                'char' => 93,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
            'line' => 30,
            'char' => 93,
          ),
          'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
          'line' => 30,
          'last-line' => 31,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
      'line' => 23,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Http/Server/AbstractRequestHandler.zep',
    'line' => 23,
    'char' => 14,
  ),
);