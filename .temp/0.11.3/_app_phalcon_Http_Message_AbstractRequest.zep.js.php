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
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
        'line' => 17,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
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
        'name' => 'Phalcon\\Http\\Message\\AbstractMessage',
        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
        'line' => 19,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
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
        'name' => 'Phalcon\\Http\\Message\\Uri',
        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
        'line' => 20,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
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
        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
        'line' => 21,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
    'line' => 25,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Request methods
 *',
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
    'line' => 26,
    'char' => 8,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'AbstractRequest',
    'abstract' => 1,
    'final' => 0,
    'extends' => 'AbstractMessage',
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'method',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'GET',
            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
            'line' => 33,
            'char' => 28,
          ),
          'docblock' => '**
     * Retrieves the HTTP method of the request.
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 33,
              'char' => 34,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 39,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'requestTarget',
          'docblock' => '**
     * The request-target, if it has been provided or calculated.
     *
     * @var null|string
     *',
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 50,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'uri',
          'docblock' => '**
     * Retrieves the URI instance.
     *
     * This method MUST return a UriInterface instance.
     *
     * @see http://tools.ietf.org/html/rfc3986#section-4.3
     *
     * @var UriInterface
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 51,
              'char' => 25,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 65,
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
          'name' => 'getRequestTarget',
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
                  'variable' => 'requestTarget',
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 68,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 70,
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
                  'variable' => 'requestTarget',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 70,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'requestTarget',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 70,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 70,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 70,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 72,
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
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 72,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'requestTarget',
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 72,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 72,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 72,
                'char' => 44,
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
                      'variable' => 'requestTarget',
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
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 73,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'uri',
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 73,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 73,
                          'char' => 43,
                        ),
                        'name' => 'getPath',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 73,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 73,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 75,
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
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                                'line' => 75,
                                'char' => 37,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'uri',
                                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                                'line' => 75,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                              'line' => 75,
                              'char' => 42,
                            ),
                            'name' => 'getQuery',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 75,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 75,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 75,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 75,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 75,
                    'char' => 55,
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
                          'operator' => 'concat-assign',
                          'variable' => 'requestTarget',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => '?',
                              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                              'line' => 76,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'property-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                                  'line' => 76,
                                  'char' => 46,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'uri',
                                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                                  'line' => 76,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                                'line' => 76,
                                'char' => 51,
                              ),
                              'name' => 'getQuery',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                              'line' => 76,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 76,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 76,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 77,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 79,
                  'char' => 14,
                ),
                2 => 
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
                          'value' => 'requestTarget',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 79,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 79,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 79,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 79,
                    'char' => 46,
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
                          'variable' => 'requestTarget',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '/',
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 80,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 80,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 81,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 84,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'requestTarget',
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 84,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 85,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves the message\'s request target.
     *
     * Retrieves the message\'s request-target either as it will appear (for
     * clients), as it appeared at request (for servers), or as it was
     * specified for the instance (see withRequestTarget()).
     *
     * In most cases, this will be the origin-form of the composed URI, unless a
     * value was provided to the concrete implementation (see
     * withRequestTarget() below).
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
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 66,
          'last-line' => 103,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 104,
              'char' => 42,
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
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 106,
                  'char' => 14,
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
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 106,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 106,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 106,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 108,
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
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 108,
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
                      'value' => 'method',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 108,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 108,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'method',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 108,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 108,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 108,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 109,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the provided HTTP method.
     *
     * While HTTP method names are typically all uppercase characters, HTTP
     * method names are case-sensitive and thus implementations SHOULD NOT
     * modify the given string.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * changed request method.
     *
     * @param string $method
     *
     * @return object
     * @throws InvalidArgumentException for invalid HTTP methods.
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
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 104,
          'last-line' => 129,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withRequestTarget',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'requestTarget',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 130,
              'char' => 56,
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
                        'value' => '/\\s/',
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 132,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 132,
                      'char' => 36,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'requestTarget',
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 132,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 132,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 132,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 132,
                'char' => 53,
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
                          'value' => 'Invalid request target: cannot contain whitespace',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 135,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 135,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 135,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 136,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 138,
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
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 138,
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
                      'value' => 'requestTarget',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 138,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 138,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'requestTarget',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 138,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 138,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 138,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 139,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specific request-target.
     *
     * If the request needs a non-origin-form request-target — e.g., for
     * specifying an absolute-form, authority-form, or asterisk-form —
     * this method may be used to create an instance with the specified
     * request-target, verbatim.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * changed request target.
     *
     * @see http://tools.ietf.org/html/rfc7230#section-5.3 (for the various
     *     request-target forms allowed in request messages)
     *
     * @param mixed $requestTarget
     *
     * @return object
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 131,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
            'line' => 131,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 130,
          'last-line' => 173,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'UriInterface',
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 174,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 174,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'preserveHost',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 174,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 174,
              'char' => 73,
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
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 176,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'newInstance',
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 176,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 178,
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
                  'variable' => 'preserveHost',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'preserveHost',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 178,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 178,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 178,
                  'char' => 51,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'headers',
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
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 179,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 179,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 179,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 179,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 179,
                  'char' => 51,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'newInstance',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 180,
                      'char' => 37,
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
                          'value' => 'uri',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 180,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 180,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 180,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 180,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 180,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 180,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 182,
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
                    'type' => 'variable',
                    'value' => 'preserveHost',
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 182,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 182,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 182,
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
                      'variable' => 'headers',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 183,
                          'char' => 32,
                        ),
                        'name' => 'checkHeaderHost',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'headers',
                              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                              'line' => 183,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 183,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 183,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 183,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 185,
                  'char' => 15,
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
                      'variable' => 'newInstance',
                      'property' => 'headers',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 185,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 185,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 186,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 188,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'newInstance',
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 188,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 189,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an instance with the provided URI.
     *
     * This method MUST update the Host header of the returned request by
     * default if the URI contains a host component. If the URI does not
     * contain a host component, any pre-existing Host header MUST be carried
     * over to the returned request.
     *
     * You can opt-in to preserving the original state of the Host header by
     * setting `$preserveHost` to `true`. When `$preserveHost` is set to
     * `true`, this method interacts with the Host header in the following
     * ways:
     *
     * - If the Host header is missing or empty, and the new URI contains
     *   a host component, this method MUST update the Host header in the
     *   returned request.
     * - If the Host header is missing or empty, and the new URI does not
     * contain a host component, this method MUST NOT update the Host header in
     * the returned request.
     * - If a Host header is present and non-empty, this method MUST NOT update
     *   the Host header in the returned request.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new UriInterface instance.
     *
     * @see http://tools.ietf.org/html/rfc3986#section-4.3
     *
     * @param UriInterface $uri
     * @param bool         $preserveHost
     *
     * @return object
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 175,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 174,
          'last-line' => 197,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'processMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 198,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 198,
              'char' => 53,
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
                  'variable' => 'methods',
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 200,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
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
                  'variable' => 'methods',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'GET',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 203,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 203,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 203,
                        'char' => 24,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'CONNECT',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 204,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 204,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 204,
                        'char' => 24,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'DELETE',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 205,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 205,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 205,
                        'char' => 24,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'HEAD',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 206,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 206,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 206,
                        'char' => 24,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'OPTIONS',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 207,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 207,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 207,
                        'char' => 24,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'PATCH',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 208,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 208,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 208,
                        'char' => 24,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'POST',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 209,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 209,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 209,
                        'char' => 24,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'PUT',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 210,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 210,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 210,
                        'char' => 24,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'TRACE',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 211,
                          'char' => 21,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 212,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 212,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 212,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 212,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 214,
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
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'and',
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
                                'type' => 'variable',
                                'value' => 'method',
                                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                                'line' => 214,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                              'line' => 214,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 214,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 214,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'method',
                              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                              'line' => 215,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 215,
                            'char' => 29,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 215,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 215,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 215,
                        'char' => 40,
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
                            'value' => 'methods',
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 216,
                            'char' => 26,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'method',
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 216,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 216,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 216,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 216,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 216,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 216,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 216,
                'char' => 36,
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
                            'value' => 'Invalid or unsupported method ',
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 218,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'method',
                            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                            'line' => 219,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 219,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 219,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 219,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 220,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 222,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'method',
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 222,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 223,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check the method
     *
     * @param string $method
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
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 199,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
            'line' => 199,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 198,
          'last-line' => 231,
          'char' => 28,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'processUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 232,
              'char' => 48,
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
                          'value' => 'uri',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 234,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 234,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 234,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 234,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'instanceof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'uri',
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 234,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'UriInterface',
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 234,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 234,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 234,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 234,
                  'char' => 76,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 234,
                'char' => 76,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'uri',
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 235,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 236,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 238,
              'char' => 10,
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
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 238,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 238,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 238,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 238,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 238,
                'char' => 41,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Uri',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                          'line' => 239,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                        'line' => 239,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 239,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 240,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 242,
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
                  'type' => 'null',
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 242,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'uri',
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 242,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 242,
                'char' => 25,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Uri',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 243,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 246,
              'char' => 13,
            ),
            3 => 
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
                      'value' => 'Invalid uri passed as a parameter',
                      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                      'line' => 248,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                    'line' => 248,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 248,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
              'line' => 249,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a valid Uri
     *
     * @param UriInterface|string|null $uri
     *
     * @return UriInterface
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
                  'value' => 'UriInterface',
                  'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                  'line' => 233,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
                'line' => 233,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
            'line' => 233,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
          'line' => 232,
          'last-line' => 250,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
      'line' => 26,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Http/Message/AbstractRequest.zep',
    'line' => 26,
    'char' => 14,
  ),
);