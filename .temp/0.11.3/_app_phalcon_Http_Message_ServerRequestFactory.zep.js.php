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
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 17,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 18,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Exception\\InvalidArgumentException',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 19,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\ServerRequest',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 20,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\UploadedFile',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 21,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Uri',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 22,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\ServerRequestFactoryInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 23,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
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
        'name' => 'Psr\\Http\\Message\\ServerRequestInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 24,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
    'line' => 25,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\UriInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 25,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
    'line' => 26,
    'char' => 3,
  ),
  11 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Psr\\Http\\Message\\UploadedFileInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 26,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
    'line' => 30,
    'char' => 2,
  ),
  12 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-17 ServerRequestFactory
 *',
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
    'line' => 31,
    'char' => 5,
  ),
  13 => 
  array (
    'type' => 'class',
    'name' => 'ServerRequestFactory',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ServerRequestFactoryInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
        'line' => 32,
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
          'name' => 'createServerRequest',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 55,
              'char' => 22,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 56,
              'char' => 16,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'serverParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 58,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 58,
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
                'class' => 'ServerRequest',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'method',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 60,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 60,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 60,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 60,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serverParams',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 60,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 60,
                    'char' => 59,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 60,
                'char' => 60,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new server request.
     *
     * Note that server-params are taken precisely as given - no
     * parsing/processing of the given values is performed, and, in particular,
     * no attempt is made to determine the HTTP method or URI, which must be
     * provided explicitly.
     *
     * @param string              $method       The HTTP method associated with
     *                                          the request.
     * @param UriInterface|string $uri          The URI associated with the
     *                                          request. If the value is a
     *                                          string, the factory MUST create
     *                                          a UriInterface instance based
     *                                          on it.
     * @param array               $serverParams Array of SAPI parameters with
     *                                          which to seed the generated
     *                                          request instance.
     *
     * @return ServerRequestInterface
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
                  'value' => 'ServerRequestInterface',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 58,
                  'char' => 35,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 58,
                'char' => 35,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 58,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 54,
          'last-line' => 80,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'load',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 82,
                'char' => 28,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 82,
              'char' => 28,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'get',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 83,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 83,
              'char' => 25,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'post',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 84,
                'char' => 26,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 84,
              'char' => 26,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'cookies',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 85,
                'char' => 29,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 85,
              'char' => 29,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'files',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 87,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 87,
              'char' => 5,
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
                  'variable' => 'cookies',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 88,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'filesCollection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 88,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 88,
                  'char' => 46,
                ),
                3 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 88,
                  'char' => 54,
                ),
                4 => 
                array (
                  'variable' => 'protocol',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 88,
                  'char' => 64,
                ),
                5 => 
                array (
                  'variable' => 'serverCollection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 88,
                  'char' => 82,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 90,
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
                  'variable' => 'server',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 90,
                      'char' => 37,
                    ),
                    'name' => 'checkNullArray',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'server',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 90,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 90,
                        'char' => 59,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => '_SERVER',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 90,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 90,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 90,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 90,
                  'char' => 69,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'files',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 91,
                      'char' => 37,
                    ),
                    'name' => 'checkNullArray',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'files',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 91,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 91,
                        'char' => 58,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => '_FILES',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 91,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 91,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 91,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 91,
                  'char' => 67,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'cookies',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 92,
                      'char' => 37,
                    ),
                    'name' => 'checkNullArray',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cookies',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 92,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 92,
                        'char' => 60,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => '_COOKIE',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 92,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 92,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 92,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 92,
                  'char' => 70,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'get',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 93,
                      'char' => 37,
                    ),
                    'name' => 'checkNullArray',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'get',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 93,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 93,
                        'char' => 56,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => '_GET',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 93,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 93,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 93,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 93,
                  'char' => 63,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'post',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 94,
                      'char' => 37,
                    ),
                    'name' => 'checkNullArray',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'post',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 94,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 94,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => '_POST',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 94,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 94,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 94,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 94,
                  'char' => 65,
                ),
                5 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'serverCollection',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 95,
                      'char' => 37,
                    ),
                    'name' => 'parseServer',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'server',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 95,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 95,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 95,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 95,
                  'char' => 57,
                ),
                6 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'method',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serverCollection',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 96,
                      'char' => 49,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'REQUEST_METHOD',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 96,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 96,
                        'char' => 68,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'GET',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 96,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 96,
                        'char' => 73,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 96,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 96,
                  'char' => 74,
                ),
                7 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'protocol',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serverCollection',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 97,
                      'char' => 49,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'SERVER_PROTOCOL',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 97,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 97,
                        'char' => 69,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '1.1',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 97,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 97,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 97,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 97,
                  'char' => 75,
                ),
                8 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 98,
                      'char' => 37,
                    ),
                    'name' => 'parseHeaders',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'serverCollection',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 98,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 98,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 98,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 98,
                  'char' => 68,
                ),
                9 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'filesCollection',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 99,
                      'char' => 37,
                    ),
                    'name' => 'parseUploadedFiles',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'files',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 99,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 99,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 99,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 99,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 101,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'list',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cookies',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 101,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 101,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 101,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 101,
                        'char' => 48,
                      ),
                      'name' => 'has',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'cookie',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 101,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 101,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 101,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 101,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 101,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 101,
                'char' => 62,
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
                      'variable' => 'cookies',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 102,
                          'char' => 32,
                        ),
                        'name' => 'parseCookieHeader',
                        'call-type' => 1,
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
                                'value' => 'headers',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 102,
                                'char' => 59,
                              ),
                              'name' => 'get',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'cookie',
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 102,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 102,
                                  'char' => 70,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 102,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 102,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 102,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 102,
                      'char' => 72,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 103,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 105,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'ServerRequest',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'method',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 106,
                      'char' => 19,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 106,
                    'char' => 19,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 107,
                        'char' => 18,
                      ),
                      'name' => 'parseUri',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'serverCollection',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 107,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 107,
                          'char' => 44,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'headers',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 107,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 107,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 107,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 107,
                    'char' => 54,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'serverCollection',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 108,
                        'char' => 30,
                      ),
                      'name' => 'toArray',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 108,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 108,
                    'char' => 40,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'php://input',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 109,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 109,
                    'char' => 24,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 110,
                        'char' => 21,
                      ),
                      'name' => 'toArray',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 110,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 110,
                    'char' => 31,
                  ),
                  5 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookies',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 111,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 111,
                    'char' => 20,
                  ),
                  6 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'get',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 112,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 112,
                    'char' => 16,
                  ),
                  7 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filesCollection',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 113,
                        'char' => 29,
                      ),
                      'name' => 'toArray',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 113,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 113,
                    'char' => 39,
                  ),
                  8 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'post',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 114,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 114,
                    'char' => 17,
                  ),
                  9 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'protocol',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 116,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 116,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 116,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 117,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a request from the supplied superglobal values.
     *
     * If any argument is not supplied, the corresponding superglobal value will
     * be used.
     *
     * The ServerRequest created is then passed to the fromServer() method in
     * order to marshal the request URI and headers.
     *
     * @param array $server  $_SERVER superglobal
     * @param array $get     $_GET superglobal
     * @param array $post    $_POST superglobal
     * @param array $cookies $_COOKIE superglobal
     * @param array $files   $_FILES superglobal
     *
     * @return ServerRequest
     * @see fromServer()
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
                  'value' => 'ServerRequest',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 87,
                  'char' => 26,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 87,
                'char' => 26,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 87,
            'char' => 26,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 81,
          'last-line' => 123,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getHeaders',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'function_exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'apache_request_headers',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 126,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 126,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 126,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 126,
                'char' => 59,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'apache_request_headers',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 127,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 128,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 130,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 130,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 131,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the apache_request_headers if it exists
     *
     * @return array|false
     *',
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 124,
          'last-line' => 140,
          'char' => 22,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'calculateUriHost',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 141,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 141,
              'char' => 58,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 141,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 141,
              'char' => 80,
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
                  'variable' => 'host',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 143,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'port',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 143,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 144,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'defaults',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 144,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 146,
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
                  'variable' => 'defaults',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 146,
                          'char' => 25,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 146,
                        'char' => 25,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 146,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 146,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 146,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 146,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 148,
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
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 148,
                    'char' => 26,
                  ),
                  'name' => 'getHeader',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 148,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 148,
                      'char' => 44,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'host',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 148,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 148,
                      'char' => 50,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 148,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 148,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 148,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 148,
                'char' => 59,
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
                      'variable' => 'host',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 149,
                          'char' => 29,
                        ),
                        'name' => 'getHeader',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'headers',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 149,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 149,
                            'char' => 47,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'host',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 149,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 149,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 149,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 149,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 150,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 150,
                      'char' => 25,
                    ),
                    'name' => 'calculateUriHostFromHeader',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'host',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 150,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 150,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 150,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 151,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 153,
              'char' => 10,
            ),
            4 => 
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
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 153,
                      'char' => 29,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'SERVER_NAME',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 153,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 153,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 153,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 153,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 153,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaults',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 154,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 155,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 157,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'host',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 157,
                      'char' => 27,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'SERVER_NAME',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 157,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 157,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 157,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 157,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'port',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 158,
                      'char' => 27,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'SERVER_PORT',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 158,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 158,
                        'char' => 43,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 158,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 158,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 158,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 158,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 160,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 160,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 160,
                    'char' => 21,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'port',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 160,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 160,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 160,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 161,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Calculates the host and port from the headers or the server superglobal
     *
     * @param Collection $server
     * @param Collection $headers
     *
     * @return array
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 142,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 142,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 141,
          'last-line' => 169,
          'char' => 20,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'calculateUriHostFromHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'host',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 170,
              'char' => 60,
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
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 172,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'port',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 172,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 174,
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
                  'variable' => 'port',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 174,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 174,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 177,
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
                  'type' => 'fcall',
                  'name' => 'preg_match',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '|:(\\d+)$|',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 177,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 177,
                      'char' => 41,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'host',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 177,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 177,
                      'char' => 47,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'matches',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 177,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 177,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 177,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 177,
                'char' => 58,
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
                      'variable' => 'host',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'host',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 178,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 178,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 178,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 178,
                            'char' => 38,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mul',
                              'left' => 
                              array (
                                'type' => 'int',
                                'value' => '-1',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 178,
                                'char' => 43,
                              ),
                              'right' => 
                              array (
                                'type' => 'list',
                                'left' => 
                                array (
                                  'type' => 'add',
                                  'left' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'strlen',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'array-access',
                                          'left' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'matches',
                                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                            'line' => 178,
                                            'char' => 60,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'int',
                                            'value' => '1',
                                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                            'line' => 178,
                                            'char' => 62,
                                          ),
                                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                          'line' => 178,
                                          'char' => 63,
                                        ),
                                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                        'line' => 178,
                                        'char' => 63,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 178,
                                    'char' => 65,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 178,
                                    'char' => 68,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 178,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 178,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 178,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 178,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 178,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 178,
                      'char' => 70,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'port',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'matches',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 179,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 179,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 179,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 179,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 179,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 180,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 182,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 182,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 182,
                    'char' => 21,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'variable',
                      'value' => 'port',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 182,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 182,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 182,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 183,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the host and calculate the port if present from the header
     *
     * @param string $host
     *
     * @return array
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 171,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 171,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 170,
          'last-line' => 192,
          'char' => 20,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'calculateUriPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 193,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 193,
              'char' => 58,
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
                  'variable' => 'iisRewrite',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 195,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'origPathInfo',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 195,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'requestUri',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 195,
                  'char' => 49,
                ),
                3 => 
                array (
                  'variable' => 'unencodedUrl',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 195,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 199,
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
                  'variable' => 'iisRewrite',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 199,
                      'char' => 35,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'IIS_WasUrlRewritten',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 199,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 199,
                        'char' => 59,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 199,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 199,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 199,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 199,
                  'char' => 66,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'unencodedUrl',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 200,
                      'char' => 35,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'UNENCODED_URL',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 200,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 200,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 200,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 200,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 200,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 200,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 202,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '1',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 202,
                        'char' => 26,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'iisRewrite',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 202,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 202,
                      'char' => 40,
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
                            'value' => 'unencodedUrl',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 202,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 202,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 202,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 202,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 202,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 202,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 202,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'unencodedUrl',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 203,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 204,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 209,
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
                  'variable' => 'requestUri',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 209,
                      'char' => 33,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'REQUEST_URI',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 209,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 209,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 209,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 209,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 209,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 209,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 211,
              'char' => 10,
            ),
            4 => 
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
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 211,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'requestUri',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 211,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 211,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 211,
                'char' => 41,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_replace',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '#^[^/:]+://[^/]+#',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 212,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 212,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 212,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 212,
                        'char' => 52,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'requestUri',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 212,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 212,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 212,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 213,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 218,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'origPathInfo',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 218,
                      'char' => 35,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'ORIG_PATH_INFO',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 218,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 218,
                        'char' => 54,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 218,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 218,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 218,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 218,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 219,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'origPathInfo',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 219,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 219,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 219,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 219,
                'char' => 42,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '/',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 220,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 221,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 223,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'origPathInfo',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 223,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 224,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the path from the request from IIS7/Rewrite, REQUEST_URL or
     * ORIG_PATH_INFO
     *
     * @param Collection $server
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
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 194,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 194,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 193,
          'last-line' => 232,
          'char' => 20,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'calculateUriQuery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 233,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 233,
              'char' => 59,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'ltrim',
                'call-type' => 1,
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
                        'value' => 'server',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 235,
                        'char' => 29,
                      ),
                      'name' => 'get',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'QUERY_STRING',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 235,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 235,
                          'char' => 46,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 235,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 235,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 235,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 235,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '?',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 235,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 235,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 235,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 236,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the query string from the server array
     *
     * @param Collection $server
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
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 234,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 234,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 233,
          'last-line' => 245,
          'char' => 20,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'calculateUriScheme',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 246,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 246,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 246,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 246,
              'char' => 82,
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
                  'variable' => 'header',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 248,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'isHttps',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 248,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 249,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'scheme',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 249,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 252,
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
                  'variable' => 'scheme',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'https',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 252,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 252,
                  'char' => 28,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'isHttps',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 253,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 253,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 254,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'server',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 254,
                    'char' => 26,
                  ),
                  'name' => 'has',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'HTTPS',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 254,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 254,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 254,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 254,
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
                      'variable' => 'isHttps',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'server',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 255,
                            'char' => 43,
                          ),
                          'name' => 'get',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'HTTPS',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 255,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 255,
                              'char' => 53,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'on',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 255,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 255,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 255,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 255,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 255,
                      'char' => 58,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'isHttps',
                      'expr' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => 'off',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 256,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strtolower',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'isHttps',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 256,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 256,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 256,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 256,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 256,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 257,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 259,
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
                  'variable' => 'header',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 259,
                      'char' => 27,
                    ),
                    'name' => 'getHeader',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'headers',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 259,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 259,
                        'char' => 45,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'x-forwarded-proto',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 259,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 259,
                        'char' => 64,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'https',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 259,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 259,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 259,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 259,
                  'char' => 72,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 260,
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
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'isHttps',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 260,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 260,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'https',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 260,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'header',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 260,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 260,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 260,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 260,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 260,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'scheme',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'http',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 261,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 261,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 262,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 264,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'scheme',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 264,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 265,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Calculates the scheme from the server variables
     *
     * @param Collection $server
     * @param Collection $headers
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
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 247,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 247,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 246,
          'last-line' => 270,
          'char' => 20,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkNullArray',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'source',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 271,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'super',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 271,
              'char' => 60,
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
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 273,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'source',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 273,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 273,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 273,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'super',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 274,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 275,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 277,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'source',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 277,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 278,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the source if it null and returns the super, otherwise the source
     * array
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 272,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 272,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 271,
          'last-line' => 288,
          'char' => 20,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'createUploadedFile',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 289,
              'char' => 51,
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 291,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 291,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 293,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'or',
                      'left' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 293,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'tmp_name',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 293,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 293,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 293,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 293,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 293,
                              'char' => 58,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'size',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 293,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 293,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 293,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 293,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 293,
                      'char' => 66,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'file',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 293,
                            'char' => 79,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'error',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 293,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 293,
                          'char' => 86,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 293,
                        'char' => 86,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 293,
                      'char' => 86,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 293,
                    'char' => 86,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 293,
                  'char' => 88,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 293,
                'char' => 88,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => 'The file array must contain tmp_name, size and error; ',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 295,
                            'char' => 72,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'one or more are missing',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 297,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 297,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 297,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 297,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 298,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 300,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 300,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 300,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 300,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 300,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 300,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'name',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 300,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 300,
                      'char' => 50,
                    ),
                    'extra' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 300,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 300,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 300,
                  'char' => 56,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'type',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 301,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 301,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 301,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 301,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 301,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'type',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 301,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 301,
                      'char' => 50,
                    ),
                    'extra' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 301,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 301,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 301,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 303,
              'char' => 14,
            ),
            3 => 
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
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 304,
                        'char' => 17,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'tmp_name',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 304,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 304,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 304,
                    'char' => 27,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 305,
                        'char' => 17,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'size',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 305,
                        'char' => 22,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 305,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 305,
                    'char' => 23,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 306,
                        'char' => 17,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'error',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 306,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 306,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 306,
                    'char' => 24,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 307,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 307,
                    'char' => 17,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 309,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 309,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 309,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 310,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create an UploadedFile object from an $_FILES array element
     *
     * @param array $file The $_FILES element
     *
     * @return UploadedFile
     *
     * @throws InvalidArgumentException If one of the elements is missing
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
                  'value' => 'UploadedFile',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 290,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 290,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 290,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 289,
          'last-line' => 320,
          'char' => 20,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 321,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 321,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 321,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 321,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 321,
              'char' => 90,
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 323,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 325,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 325,
                      'char' => 29,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 325,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 325,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultValue',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 325,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 325,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 325,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 325,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 327,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 327,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 327,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 327,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 327,
                'char' => 35,
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
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'implode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => ',',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 328,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 328,
                            'char' => 34,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 328,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 328,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 328,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 328,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 329,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 331,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 331,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 332,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a header
     *
     * @param Collection $headers
     * @param string     $name
     * @param mixed|null $defaultValue
     *
     * @return mixed|string
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
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 322,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 322,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 321,
          'last-line' => 341,
          'char' => 20,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'parseCookieHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cookieHeader',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 342,
              'char' => 59,
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
                  'variable' => 'cookies',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 344,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 346,
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
                  'variable' => 'cookies',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 346,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 346,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 347,
              'char' => 17,
            ),
            2 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'parse_str',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strtr',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'cookieHeader',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 349,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 349,
                          'char' => 29,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'array',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => '&',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 351,
                                  'char' => 23,
                                ),
                                'value' => 
                                array (
                                  'type' => 'string',
                                  'value' => '%26',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 351,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 351,
                                'char' => 28,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => '+',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 352,
                                  'char' => 23,
                                ),
                                'value' => 
                                array (
                                  'type' => 'string',
                                  'value' => '%2B',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 352,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 352,
                                'char' => 28,
                              ),
                              2 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => ';',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 353,
                                  'char' => 23,
                                ),
                                'value' => 
                                array (
                                  'type' => 'string',
                                  'value' => '&',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 354,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 354,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 355,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 355,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 355,
                      'char' => 14,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 355,
                    'char' => 14,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookies',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 357,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 357,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 357,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 359,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'cookies',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 359,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 360,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Parse a cookie header according to RFC 6265.
     *
     * @param string $cookieHeader A string cookie header value.
     *
     * @return array key/value cookie pairs.
     *
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 343,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 343,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 342,
          'last-line' => 368,
          'char' => 20,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'parseHeaders',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 369,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 369,
              'char' => 54,
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
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 371,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 371,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 371,
                  'char' => 31,
                ),
                3 => 
                array (
                  'variable' => 'serverArray',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 371,
                  'char' => 44,
                ),
                4 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 371,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 376,
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
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 376,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 376,
                  'char' => 43,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'serverArray',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'server',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 377,
                      'char' => 34,
                    ),
                    'name' => 'toArray',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 377,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 377,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 379,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'serverArray',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 379,
                'char' => 39,
              ),
              'key' => 'key',
              'value' => 'value',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'likely',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 380,
                        'char' => 26,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 380,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 380,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 380,
                    'char' => 34,
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
                            'type' => 'fcall',
                            'name' => 'strpos',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 385,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 385,
                                'char' => 39,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'REDIRECT_',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 385,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 385,
                                'char' => 50,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 385,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 385,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 385,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 385,
                        'char' => 58,
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
                              'variable' => 'key',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'substr',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'key',
                                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                      'line' => 386,
                                      'char' => 41,
                                    ),
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 386,
                                    'char' => 41,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '9',
                                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                      'line' => 386,
                                      'char' => 44,
                                    ),
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 386,
                                    'char' => 44,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 386,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 386,
                              'char' => 45,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 391,
                          'char' => 22,
                        ),
                        1 => 
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
                                'type' => 'identical',
                                'left' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 391,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'server',
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 391,
                                    'char' => 50,
                                  ),
                                  'name' => 'has',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'key',
                                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                        'line' => 391,
                                        'char' => 58,
                                      ),
                                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                      'line' => 391,
                                      'char' => 58,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 391,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 391,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 391,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 391,
                            'char' => 61,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'continue',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 393,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 394,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 396,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'likely',
                        'left' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'strpos',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 396,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 396,
                                'char' => 37,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'HTTP_',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 396,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 396,
                                'char' => 44,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 396,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 396,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 396,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 396,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'name',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'str_replace',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '_',
                                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                      'line' => 398,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 398,
                                    'char' => 26,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '-',
                                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                      'line' => 399,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 399,
                                    'char' => 26,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'strtolower',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'fcall',
                                            'name' => 'substr',
                                            'call-type' => 1,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'key',
                                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                                  'line' => 400,
                                                  'char' => 46,
                                                ),
                                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                                'line' => 400,
                                                'char' => 46,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '5',
                                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                                  'line' => 400,
                                                  'char' => 49,
                                                ),
                                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                                'line' => 400,
                                                'char' => 49,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                            'line' => 400,
                                            'char' => 50,
                                          ),
                                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                          'line' => 400,
                                          'char' => 50,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                      'line' => 401,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 401,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 401,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 401,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 403,
                          'char' => 27,
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
                              'value' => 'headers',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 403,
                              'char' => 29,
                            ),
                            'name' => 'set',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 403,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 403,
                                'char' => 38,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 403,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 403,
                                'char' => 45,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 403,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 404,
                          'char' => 28,
                        ),
                        2 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 405,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 407,
                      'char' => 18,
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
                            'type' => 'fcall',
                            'name' => 'strpos',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 407,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 407,
                                'char' => 39,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'CONTENT_',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 407,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 407,
                                'char' => 49,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 407,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 407,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 407,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 407,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'name',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'content-',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 408,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'strtolower',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'substr',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'key',
                                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                              'line' => 408,
                                              'char' => 64,
                                            ),
                                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                            'line' => 408,
                                            'char' => 64,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '8',
                                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                              'line' => 408,
                                              'char' => 67,
                                            ),
                                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                            'line' => 408,
                                            'char' => 67,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                        'line' => 408,
                                        'char' => 68,
                                      ),
                                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                      'line' => 408,
                                      'char' => 68,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 408,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 408,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 408,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 410,
                          'char' => 27,
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
                              'value' => 'headers',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 410,
                              'char' => 29,
                            ),
                            'name' => 'set',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 410,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 410,
                                'char' => 38,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 410,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 410,
                                'char' => 45,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 410,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 411,
                          'char' => 28,
                        ),
                        2 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 412,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 413,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 414,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 416,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'headers',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 416,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 417,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Processes headers from SAPI
     *
     * @param Collection $server
     *
     * @return Collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 370,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 370,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 370,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 369,
          'last-line' => 427,
          'char' => 20,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'parseServer',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 428,
              'char' => 46,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 430,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 430,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'headersCollection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 430,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 432,
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
                  'variable' => 'collection',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'server',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 432,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 432,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 432,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 432,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 433,
                      'char' => 31,
                    ),
                    'name' => 'getHeaders',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 433,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 433,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 435,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 435,
                          'char' => 34,
                        ),
                        'name' => 'has',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'HTTP_AUTHORIZATION',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 435,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 435,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 435,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 435,
                      'char' => 60,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 435,
                        'char' => 70,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 435,
                        'char' => 79,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 435,
                      'char' => 79,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 435,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 435,
                  'char' => 81,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 435,
                'char' => 81,
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
                      'variable' => 'headersCollection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Collection',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'headers',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 436,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 436,
                            'char' => 59,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 436,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 436,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 438,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'likely',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headersCollection',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 438,
                        'char' => 41,
                      ),
                      'name' => 'has',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'Authorization',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 438,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 438,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 438,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 438,
                    'char' => 61,
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
                          'value' => 'collection',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 439,
                          'char' => 28,
                        ),
                        'name' => 'set',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'HTTP_AUTHORIZATION',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 440,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 440,
                            'char' => 39,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'headersCollection',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 441,
                                'char' => 39,
                              ),
                              'name' => 'get',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Authorization',
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 441,
                                    'char' => 57,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 441,
                                  'char' => 57,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 442,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 442,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 442,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 443,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 444,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 446,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 446,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 447,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Parse the $_SERVER array amd return it back after looking for the
     * authorization header
     *
     * @param array $server Either verbatim, or with an added
     *                      HTTP_AUTHORIZATION header.
     *
     * @return Collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 429,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 429,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 429,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 428,
          'last-line' => 456,
          'char' => 20,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'parseUploadedFiles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'files',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 457,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 459,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'data',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 459,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 459,
                  'char' => 34,
                ),
                3 => 
                array (
                  'variable' => 'file',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 459,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 461,
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
                  'variable' => 'collection',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 461,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 461,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 466,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'files',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 466,
                'char' => 33,
              ),
              'key' => 'key',
              'value' => 'file',
              'reverse' => 0,
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
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 467,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 467,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 467,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 472,
                  'char' => 14,
                ),
                1 => 
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
                              'value' => 'file',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 472,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 472,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 472,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 472,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'instanceof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'file',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 472,
                            'char' => 66,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'UploadedFileInterface',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 472,
                            'char' => 89,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 472,
                          'char' => 89,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 472,
                        'char' => 89,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 472,
                      'char' => 91,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 472,
                    'char' => 91,
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
                          'value' => 'collection',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 473,
                          'char' => 28,
                        ),
                        'name' => 'set',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 473,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 473,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 473,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 473,
                            'char' => 42,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 473,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 474,
                      'char' => 24,
                    ),
                    1 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 475,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 480,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'likely',
                    'left' => 
                    array (
                      'type' => 'list',
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
                              'value' => 'file',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 480,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 480,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 480,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 480,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 480,
                              'char' => 59,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'tmp_name',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 480,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 480,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 480,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 480,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 480,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 480,
                    'char' => 71,
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
                          'value' => 'collection',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 481,
                          'char' => 28,
                        ),
                        'name' => 'set',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 481,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 481,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 481,
                                'char' => 43,
                              ),
                              'name' => 'createUploadedFile',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'file',
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 481,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 481,
                                  'char' => 67,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 481,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 481,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 481,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 482,
                      'char' => 24,
                    ),
                    1 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 483,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 488,
                  'char' => 14,
                ),
                3 => 
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
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 488,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 488,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 488,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 488,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 488,
                    'char' => 47,
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
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 489,
                              'char' => 33,
                            ),
                            'name' => 'parseUploadedFiles',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'file',
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 489,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 489,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 489,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 489,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 491,
                      'char' => 26,
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
                          'value' => 'collection',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 491,
                          'char' => 28,
                        ),
                        'name' => 'set',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 491,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 491,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'data',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 491,
                                'char' => 43,
                              ),
                              'name' => 'toArray',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 491,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 491,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 491,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 492,
                      'char' => 24,
                    ),
                    2 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 493,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 494,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 496,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 496,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 497,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Traverses a $_FILES and creates UploadedFile objects from it. It is used
     * recursively
     *
     * @param array $files
     *
     * @return Collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 458,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 458,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 458,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 457,
          'last-line' => 506,
          'char' => 20,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'parseUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'server',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 507,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 507,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 507,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 507,
              'char' => 72,
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
                  'variable' => 'path',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 509,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'query',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 509,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'scheme',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 509,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'split',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 509,
                  'char' => 39,
                ),
                4 => 
                array (
                  'variable' => 'uri',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 509,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 511,
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
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Uri',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 511,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 511,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 516,
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
                  'variable' => 'scheme',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 516,
                      'char' => 27,
                    ),
                    'name' => 'calculateUriScheme',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'server',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 516,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 516,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'headers',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 516,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 516,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 516,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 516,
                  'char' => 63,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 517,
                      'char' => 26,
                    ),
                    'name' => 'withScheme',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'scheme',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 517,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 517,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 517,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 517,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 522,
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
                  'variable' => 'split',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 522,
                      'char' => 26,
                    ),
                    'name' => 'calculateUriHost',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'server',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 522,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 522,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'headers',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 522,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 522,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 522,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 522,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 523,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
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
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'split',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 523,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 523,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 523,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 523,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 523,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 523,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 523,
                'char' => 36,
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
                      'variable' => 'uri',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 524,
                          'char' => 27,
                        ),
                        'name' => 'withHost',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'split',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 524,
                                'char' => 42,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 524,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 524,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 524,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 524,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 524,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 525,
                  'char' => 14,
                ),
                1 => 
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
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'split',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 525,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 525,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 525,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 525,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 525,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 525,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 525,
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
                          'variable' => 'uri',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'uri',
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 526,
                              'char' => 31,
                            ),
                            'name' => 'withPort',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'split',
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 526,
                                    'char' => 46,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                    'line' => 526,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                  'line' => 526,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 526,
                                'char' => 49,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 526,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 526,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 527,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 528,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 533,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 533,
                      'char' => 26,
                    ),
                    'name' => 'calculateUriPath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'server',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 533,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 533,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 533,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 533,
                  'char' => 51,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'split',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'explode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '#',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 534,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 534,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 534,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 534,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 534,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 534,
                  'char' => 37,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'explode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '?',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 535,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 535,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'split',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 535,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 535,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 535,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 535,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 535,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 535,
                  'char' => 41,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 536,
                      'char' => 25,
                    ),
                    'name' => 'withPath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'path',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 536,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 536,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 536,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 536,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 536,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 536,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 538,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'greater',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'split',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 538,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 538,
                        'char' => 32,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 538,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 538,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 538,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 538,
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
                      'variable' => 'uri',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 539,
                          'char' => 27,
                        ),
                        'name' => 'withFragment',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'split',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 539,
                                'char' => 46,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                                'line' => 539,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                              'line' => 539,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                            'line' => 539,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 539,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 539,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 540,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 545,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'query',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 545,
                      'char' => 26,
                    ),
                    'name' => 'calculateUriQuery',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'server',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 545,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 545,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 545,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 545,
                  'char' => 52,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                      'line' => 546,
                      'char' => 25,
                    ),
                    'name' => 'withQuery',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'query',
                          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                          'line' => 546,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                        'line' => 546,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                    'line' => 546,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 546,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 548,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'uri',
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 548,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
              'line' => 549,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Calculates the Uri from the server superglobal or the headers
     *
     * @param Collection $server
     * @param Collection $headers
     *
     * @return Uri
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
                  'value' => 'Uri',
                  'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                  'line' => 508,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
                'line' => 508,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
            'line' => 508,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
          'line' => 507,
          'last-line' => 550,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
      'line' => 31,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequestFactory.zep',
    'line' => 31,
    'char' => 5,
  ),
);