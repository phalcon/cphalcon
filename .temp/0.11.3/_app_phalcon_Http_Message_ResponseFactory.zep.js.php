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
    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Response',
        'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
        'line' => 17,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\ResponseInterface',
        'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
        'line' => 18,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\ResponseFactoryInterface',
        'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
        'line' => 19,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
    'line' => 23,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-17 ResponseFactory
 *',
    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
    'line' => 24,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'ResponseFactory',
    'abstract' => 0,
    'final' => 1,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ResponseFactoryInterface',
        'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
        'line' => 25,
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
          'name' => 'createResponse',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '200',
                'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                'line' => 37,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
              'line' => 37,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'reasonPhrase',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                'line' => 37,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
              'line' => 37,
              'char' => 74,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'new',
                    'class' => 'Response',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                    'line' => 39,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                  'line' => 39,
                  'char' => 33,
                ),
                'name' => 'withStatus',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                      'line' => 39,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                    'line' => 39,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reasonPhrase',
                      'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                      'line' => 39,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                    'line' => 39,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                'line' => 39,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new response.
     *
     * @param int    $code         The HTTP status code. Defaults to 200.
     * @param string $reasonPhrase The reason phrase to associate with the status
     *                             code in the generated response. If none is
     *                             provided, implementations MAY use the defaults
     *                             as suggested in the HTTP specification.
     *
     * @return ResponseInterface
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
                  'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                  'line' => 38,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
                'line' => 38,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
            'line' => 38,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
          'line' => 37,
          'last-line' => 41,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
      'line' => 24,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/ResponseFactory.zep',
    'line' => 24,
    'char' => 11,
  ),
);