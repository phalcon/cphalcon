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
    'file' => '/app/phalcon/Http/Message/Request.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/Request.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Stream\\Input',
        'file' => '/app/phalcon/Http/Message/Request.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Request.zep',
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
        'name' => 'Phalcon\\Http\\Message\\AbstractRequest',
        'file' => '/app/phalcon/Http/Message/Request.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Request.zep',
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
        'name' => 'Psr\\Http\\Message\\RequestInterface',
        'file' => '/app/phalcon/Http/Message/Request.zep',
        'line' => 19,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Request.zep',
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
        'file' => '/app/phalcon/Http/Message/Request.zep',
        'line' => 20,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Request.zep',
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
        'name' => 'Psr\\Http\\Message\\UriInterface',
        'file' => '/app/phalcon/Http/Message/Request.zep',
        'line' => 21,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Request.zep',
    'line' => 25,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-7 Request
 *',
    'file' => '/app/phalcon/Http/Message/Request.zep',
    'line' => 26,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Request',
    'abstract' => 0,
    'final' => 1,
    'extends' => 'AbstractRequest',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RequestInterface',
        'file' => '/app/phalcon/Http/Message/Request.zep',
        'line' => 27,
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
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'GET',
                'file' => '/app/phalcon/Http/Message/Request.zep',
                'line' => 37,
                'char' => 28,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Request.zep',
              'line' => 37,
              'char' => 28,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/Request.zep',
                'line' => 38,
                'char' => 23,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Request.zep',
              'line' => 38,
              'char' => 23,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'body',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'php://memory',
                'file' => '/app/phalcon/Http/Message/Request.zep',
                'line' => 39,
                'char' => 32,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Request.zep',
              'line' => 39,
              'char' => 32,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Message/Request.zep',
                'line' => 41,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Request.zep',
              'line' => 41,
              'char' => 5,
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
                    'type' => 'string',
                    'value' => 'php://input',
                    'file' => '/app/phalcon/Http/Message/Request.zep',
                    'line' => 42,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'body',
                    'file' => '/app/phalcon/Http/Message/Request.zep',
                    'line' => 42,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/Request.zep',
                  'line' => 42,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Http/Message/Request.zep',
                'line' => 42,
                'char' => 42,
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
                      'variable' => 'body',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Input',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Http/Message/Request.zep',
                        'line' => 43,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Http/Message/Request.zep',
                      'line' => 43,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Request.zep',
                  'line' => 44,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Request.zep',
              'line' => 46,
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
                  'property' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Request.zep',
                      'line' => 46,
                      'char' => 34,
                    ),
                    'name' => 'processUri',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Http/Message/Request.zep',
                          'line' => 46,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Http/Message/Request.zep',
                        'line' => 46,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Request.zep',
                    'line' => 46,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Http/Message/Request.zep',
                  'line' => 46,
                  'char' => 50,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Request.zep',
                      'line' => 47,
                      'char' => 34,
                    ),
                    'name' => 'processHeaders',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'headers',
                          'file' => '/app/phalcon/Http/Message/Request.zep',
                          'line' => 47,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/Request.zep',
                        'line' => 47,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Request.zep',
                    'line' => 47,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Http/Message/Request.zep',
                  'line' => 47,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'method',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Request.zep',
                      'line' => 48,
                      'char' => 34,
                    ),
                    'name' => 'processMethod',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Http/Message/Request.zep',
                          'line' => 48,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Message/Request.zep',
                        'line' => 48,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Request.zep',
                    'line' => 48,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Http/Message/Request.zep',
                  'line' => 48,
                  'char' => 56,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'body',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Request.zep',
                      'line' => 49,
                      'char' => 34,
                    ),
                    'name' => 'processBody',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'body',
                          'file' => '/app/phalcon/Http/Message/Request.zep',
                          'line' => 49,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Http/Message/Request.zep',
                        'line' => 49,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'w+b',
                          'file' => '/app/phalcon/Http/Message/Request.zep',
                          'line' => 49,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Message/Request.zep',
                        'line' => 49,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Request.zep',
                    'line' => 49,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Http/Message/Request.zep',
                  'line' => 49,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Request.zep',
              'line' => 50,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Request constructor.
     *
     * @param string                          $method
     * @param UriInterface|string|null        $uri
     * @param StreamInterface|resource|string $body
     * @param array                           $headers
     *',
          'file' => '/app/phalcon/Http/Message/Request.zep',
          'line' => 36,
          'last-line' => 51,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/Request.zep',
      'line' => 26,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/Request.zep',
    'line' => 26,
    'char' => 11,
  ),
);