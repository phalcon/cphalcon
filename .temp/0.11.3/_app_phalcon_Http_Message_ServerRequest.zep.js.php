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
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 17,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 19,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Stream\\Input',
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 20,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'name' => 'Psr\\Http\\Message\\ServerRequestInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 21,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 22,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 23,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
        'name' => 'Psr\\Http\\Message\\UriInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
        'line' => 24,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
    'line' => 28,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-7 ServerRequest
 *',
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
    'line' => 29,
    'char' => 5,
  ),
  11 => 
  array (
    'type' => 'class',
    'name' => 'ServerRequest',
    'abstract' => 0,
    'final' => 1,
    'extends' => 'AbstractRequest',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ServerRequestInterface',
        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
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
          'name' => 'attributes',
          'docblock' => '**
     * @var Collection
     *',
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 45,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'cookieParams',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 46,
            'char' => 31,
          ),
          'docblock' => '**
     * Retrieve cookies.
     *
     * Retrieves cookies sent by the client to the server.
     *
     * The data MUST be compatible with the structure of the $_COOKIE
     * superglobal.
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 46,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 61,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'parsedBody',
          'docblock' => '**
     * Retrieve any parameters provided in the request body.
     *
     * If the request Content-Type is either application/x-www-form-urlencoded
     * or multipart/form-data, and the request method is POST, this method MUST
     * return the contents of $_POST.
     *
     * Otherwise, this method may return any results of deserializing
     * the request body content; as parsing returns structured content, the
     * potential types MUST be arrays or objects only. A null value indicates
     * the absence of body content.
     *
     * @var mixed
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 62,
              'char' => 30,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 75,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'queryParams',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 76,
            'char' => 30,
          ),
          'docblock' => '**
     * Retrieve query string arguments.
     *
     * Retrieves the deserialized query string arguments, if any.
     *
     * Note: the query params might not be in sync with the URI or server
     * params. If you need to ensure you are only getting the original
     * values, you may need to parse the query string from
     * `getUri()->getQuery()` or from the `QUERY_STRING` server param.
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 76,
              'char' => 36,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 86,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'serverParams',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 87,
            'char' => 31,
          ),
          'docblock' => '**
     * Retrieve server parameters.
     *
     * Retrieves data related to the incoming request environment,
     * typically derived from PHP\'s $_SERVER superglobal. The data IS NOT
     * REQUIRED to originate from $_SERVER.
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 87,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 99,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'uploadedFiles',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 100,
            'char' => 32,
          ),
          'docblock' => '**
     * Retrieve normalized file upload data.
     *
     * This method returns upload metadata in a normalized tree, with each leaf
     * an instance of Psr\\Http\\Message\\UploadedFileInterface.
     *
     * These values MAY be prepared from $_FILES or the message body during
     * instantiation, or MAY be injected via withUploadedFiles().
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 100,
              'char' => 38,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 115,
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
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'GET',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 117,
                'char' => 28,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 117,
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
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 118,
                'char' => 23,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 118,
              'char' => 23,
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
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 119,
                'char' => 32,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 119,
              'char' => 32,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'body',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'php://input',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 120,
                'char' => 31,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 120,
              'char' => 31,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'headers',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 121,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 121,
              'char' => 25,
            ),
            5 => 
            array (
              'type' => 'parameter',
              'name' => 'cookies',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 122,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 122,
              'char' => 27,
            ),
            6 => 
            array (
              'type' => 'parameter',
              'name' => 'queryParams',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 123,
                'char' => 31,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 123,
              'char' => 31,
            ),
            7 => 
            array (
              'type' => 'parameter',
              'name' => 'uploadFiles',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 124,
                'char' => 31,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 124,
              'char' => 31,
            ),
            8 => 
            array (
              'type' => 'parameter',
              'name' => 'parsedBody',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 125,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 125,
              'char' => 30,
            ),
            9 => 
            array (
              'type' => 'parameter',
              'name' => 'protocol',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '1.1',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 127,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 127,
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
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 128,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'body',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 128,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 128,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 128,
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
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 129,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 129,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 130,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 132,
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
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 132,
                  'char' => 14,
                ),
                'name' => 'checkUploadedFiles',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uploadFiles',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 132,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 132,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 132,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 134,
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
                  'property' => 'protocolVersion',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 134,
                      'char' => 42,
                    ),
                    'name' => 'processProtocol',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'protocol',
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 134,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 134,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 134,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 134,
                  'char' => 68,
                ),
                1 => 
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
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 135,
                      'char' => 42,
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
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 135,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 135,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 135,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 135,
                  'char' => 64,
                ),
                2 => 
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
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 136,
                      'char' => 42,
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
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 136,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 136,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 136,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 136,
                  'char' => 66,
                ),
                3 => 
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
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 137,
                      'char' => 42,
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
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 137,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 137,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 137,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 137,
                  'char' => 58,
                ),
                4 => 
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
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 138,
                      'char' => 42,
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
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 138,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 138,
                        'char' => 59,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'w+b',
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 138,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 138,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 138,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 138,
                  'char' => 65,
                ),
                5 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'uploadedFiles',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'uploadFiles',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 139,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 139,
                  'char' => 48,
                ),
                6 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'parsedBody',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parsedBody',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 140,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 140,
                  'char' => 47,
                ),
                7 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'serverParams',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'serverParams',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 141,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 141,
                  'char' => 49,
                ),
                8 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'cookieParams',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cookies',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 142,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 142,
                  'char' => 44,
                ),
                9 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'queryParams',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'queryParams',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 143,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 143,
                  'char' => 48,
                ),
                10 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 144,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 144,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 145,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * ServerRequest constructor.
     *
     * @param string                   $method
     * @param UriInterface|string|null $uri
     * @param array                    $serverParams
     * @param StreamInterface|string   $body
     * @param array                    $headers
     * @param array                    $cookies
     * @param array                    $queryParams
     * @param array                    $uploadFiles
     * @param null|array|object        $parsedBody
     * @param string                   $protocol
     *',
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 116,
          'last-line' => 161,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 162,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 162,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 162,
              'char' => 67,
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 164,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 164,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 164,
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
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 164,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 164,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 164,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 164,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 164,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 165,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieve a single derived request attribute.
     *
     * Retrieves a single derived request attribute as described in
     * getAttributes(). If the attribute has not been previously set, returns
     * the default value as provided.
     *
     * This method obviates the need for a hasAttribute() method, as it allows
     * specifying a default value to return if the attribute is not found.
     *
     * @param string        $name
     * @param mixed|null    $defaultValue
     *
     * @return mixed
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
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 163,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 162,
          'last-line' => 177,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAttributes',
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 180,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 180,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 180,
                  'char' => 33,
                ),
                'name' => 'toArray',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 180,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 181,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieve attributes derived from the request.
     *
     * The request \'attributes\' may be used to allow injection of any
     * parameters derived from the request: e.g., the results of path
     * match operations; the results of decrypting cookies; the results of
     * deserializing non-form-encoded message bodies; etc. Attributes
     * will be application and request specific, and CAN be mutable.
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
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 179,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 179,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 178,
          'last-line' => 197,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 198,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 198,
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
                  'variable' => 'attributes',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 200,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 202,
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
                  'variable' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 202,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 202,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 202,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 202,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 202,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 204,
              'char' => 18,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'attributes',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 204,
                  'char' => 20,
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
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 204,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 204,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 204,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 204,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 204,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 206,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 206,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 206,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 206,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 206,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 206,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 206,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 207,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified derived request attribute.
     *
     * This method allows setting a single derived request attribute as
     * described in getAttributes().
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated attribute.
     *
     * @param string $name
     * @param mixed  $value
     *
     * @return ServerRequest
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
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 199,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 199,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 199,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 198,
          'last-line' => 226,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withCookieParams',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cookies',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 227,
              'char' => 51,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 229,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cookies',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 229,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 229,
                    'char' => 43,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'cookieParams',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 229,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 229,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 229,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 230,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified cookies.
     *
     * The data IS NOT REQUIRED to come from the $_COOKIE superglobal, but MUST
     * be compatible with the structure of $_COOKIE. Typically, this data will
     * be injected at instantiation.
     *
     * This method MUST NOT update the related Cookie header of the request
     * instance, nor related values in the server params.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated cookie values.
     *
     * @param array $cookies
     *
     * @return ServerRequest
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
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 228,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 228,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 228,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 227,
          'last-line' => 260,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withParsedBody',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 261,
              'char' => 40,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 263,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 263,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 263,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'parsedBody',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 263,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 263,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 263,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 264,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified body parameters.
     *
     * These MAY be injected during instantiation.
     *
     * If the request Content-Type is either application/x-www-form-urlencoded
     * or multipart/form-data, and the request method is POST, use this method
     * ONLY to inject the contents of $_POST.
     *
     * The data IS NOT REQUIRED to come from $_POST, but MUST be the results of
     * deserializing the request body content. Deserialization/parsing returns
     * structured data, and, as such, this method ONLY accepts arrays or
     * objects, or a null value if nothing was available to parse.
     *
     * As an example, if content negotiation determines that the request data
     * is a JSON payload, this method could be used to create a request
     * instance with the deserialized parameters.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated body parameters.
     *
     * @param array|object|null $data
     *
     * @return ServerRequest
     * @throws InvalidArgumentException if an unsupported argument type is
     *     provided.
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServerRequest',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 262,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 262,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 262,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 261,
          'last-line' => 287,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withQueryParams',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'query',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 288,
              'char' => 48,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 290,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'query',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 290,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 290,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'queryParams',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 290,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 290,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 290,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 291,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified query string arguments.
     *
     * These values SHOULD remain immutable over the course of the incoming
     * request. They MAY be injected during instantiation, such as from PHP\'s
     * $_GET superglobal, or MAY be derived from some other value such as the
     * URI. In cases where the arguments are parsed from the URI, the data
     * MUST be compatible with what PHP\'s parse_str() would return for
     * purposes of how duplicate query parameters are handled, and how nested
     * sets are handled.
     *
     * Setting query string arguments MUST NOT change the URI stored by the
     * request, nor the values in the server params.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated query string arguments.
     *
     * @param array $query
     *
     * @return ServerRequest
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
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 289,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 289,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 289,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 288,
          'last-line' => 305,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withUploadedFiles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uploadedFiles',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 306,
              'char' => 58,
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
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 308,
                  'char' => 14,
                ),
                'name' => 'checkUploadedFiles',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uploadedFiles',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 308,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 308,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 308,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 310,
              'char' => 14,
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
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 310,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uploadedFiles',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 310,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 310,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'uploadedFiles',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 310,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 310,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 310,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 311,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new instance with the specified uploaded files.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated body parameters.
     *
     * @param array $uploadedFiles
     *
     * @return ServerRequest
     * @throws InvalidArgumentException if an invalid structure is provided.
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ServerRequest',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 307,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 307,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 307,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 306,
          'last-line' => 326,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withoutAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 327,
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
                  'variable' => 'attributes',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 329,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 331,
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
                  'variable' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 331,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 331,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 331,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 331,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 331,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 332,
              'char' => 18,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'attributes',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 332,
                  'char' => 20,
                ),
                'name' => 'remove',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 332,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 332,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 332,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 334,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 334,
                  'char' => 21,
                ),
                'name' => 'cloneInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 334,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 334,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 334,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 334,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 334,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 335,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance that removes the specified derived request attribute.
     *
     * This method allows removing a single derived request attribute as
     * described in getAttributes().
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that removes
     * the attribute.
     *
     * @param string $name
     *
     * @return ServerRequest
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
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 328,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 328,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 328,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 327,
          'last-line' => 341,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkUploadedFiles',
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
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 342,
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
                  'variable' => 'file',
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 344,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 346,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'files',
                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                'line' => 346,
                'char' => 27,
              ),
              'value' => 'file',
              'reverse' => 0,
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
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 347,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 347,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 347,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 347,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                    'line' => 347,
                    'char' => 47,
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
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 348,
                          'char' => 22,
                        ),
                        'name' => 'checkUploadedFiles',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                              'line' => 348,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                            'line' => 348,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 348,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 349,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
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
                                'type' => 'identical',
                                'left' => 
                                array (
                                  'type' => 'typeof',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'file',
                                    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                    'line' => 350,
                                    'char' => 45,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                  'line' => 350,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'object',
                                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                  'line' => 350,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                'line' => 350,
                                'char' => 55,
                              ),
                              'right' => 
                              array (
                                'type' => 'instanceof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'file',
                                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                  'line' => 350,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'UploadedFileInterface',
                                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                  'line' => 350,
                                  'char' => 94,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                'line' => 350,
                                'char' => 94,
                              ),
                              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                              'line' => 350,
                              'char' => 94,
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                            'line' => 350,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 350,
                          'char' => 96,
                        ),
                        'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                        'line' => 350,
                        'char' => 96,
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
                                  'value' => 'Invalid uploaded file',
                                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                  'line' => 351,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                                'line' => 351,
                                'char' => 77,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                            'line' => 351,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                          'line' => 352,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                      'line' => 353,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
                  'line' => 354,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
              'line' => 355,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the uploaded files
     *
     * @param array $files
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
            'line' => 343,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
          'line' => 342,
          'last-line' => 356,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
      'line' => 29,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/ServerRequest.zep',
    'line' => 29,
    'char' => 11,
  ),
);