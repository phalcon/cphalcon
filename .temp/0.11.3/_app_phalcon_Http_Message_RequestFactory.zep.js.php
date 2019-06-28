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
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Request',
        'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
        'line' => 17,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\RequestInterface',
        'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
        'line' => 18,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\RequestFactoryInterface',
        'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
        'line' => 19,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\UriInterface',
        'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
        'line' => 20,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
    'line' => 24,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-17 RequestFactory
 *',
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
    'line' => 25,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'RequestFactory',
    'abstract' => 0,
    'final' => 1,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RequestFactoryInterface',
        'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
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
          'name' => 'createRequest',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
              'line' => 35,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
              'line' => 35,
              'char' => 58,
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
                'class' => 'Request',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'method',
                      'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
                      'line' => 37,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
                    'line' => 37,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
                      'line' => 37,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
                    'line' => 37,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
                'line' => 37,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
              'line' => 38,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new request.
     *
     * @param string                   $method
     * @param UriInterface|string|null $uri
     *
     * @return RequestInterface
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
                  'value' => 'RequestInterface',
                  'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
                  'line' => 36,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
                'line' => 36,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
            'line' => 36,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
          'line' => 35,
          'last-line' => 39,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
      'line' => 25,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/RequestFactory.zep',
    'line' => 25,
    'char' => 11,
  ),
);