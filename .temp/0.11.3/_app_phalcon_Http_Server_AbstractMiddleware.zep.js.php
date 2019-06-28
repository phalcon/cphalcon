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
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Server',
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
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
        'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
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
        'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
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
        'name' => 'Psr\\Http\\Server\\MiddlewareInterface',
        'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
        'line' => 15,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Server\\RequestHandlerInterface',
        'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
        'line' => 16,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
    'line' => 24,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Participant in processing a server request and response.
 *
 * An HTTP middleware component participates in processing an HTTP message:
 * by acting on the request, generating the response, or forwarding the
 * request to a subsequent middleware and possibly acting on its response.
 *',
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
    'line' => 25,
    'char' => 8,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'AbstractMiddleware',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'MiddlewareInterface',
        'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
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
            0 => 'abstract',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'process',
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
                'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
                'line' => 35,
                'char' => 40,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
              'line' => 35,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'RequestHandlerInterface',
                'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
                'line' => 36,
                'char' => 41,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
              'line' => 37,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Process an incoming server request.
     *
     * Processes an incoming server request in order to produce a response.
     * If unable to produce the response itself, it may delegate to the provided
     * request handler to do so.
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
                  'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
                  'line' => 37,
                  'char' => 29,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
                'line' => 37,
                'char' => 29,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
            'line' => 37,
            'char' => 29,
          ),
          'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
          'line' => 34,
          'last-line' => 38,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
      'line' => 25,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Http/Server/AbstractMiddleware.zep',
    'line' => 25,
    'char' => 14,
  ),
);