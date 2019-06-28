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
    'file' => '/app/phalcon/Http/Message/Uri.zep',
    'line' => 15,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Message',
    'file' => '/app/phalcon/Http/Message/Uri.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Http/Message/Uri.zep',
        'line' => 17,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Uri.zep',
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
        'name' => 'Phalcon\\Helper\\Str',
        'file' => '/app/phalcon/Http/Message/Uri.zep',
        'line' => 18,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Uri.zep',
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
        'file' => '/app/phalcon/Http/Message/Uri.zep',
        'line' => 19,
        'char' => 60,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Uri.zep',
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
        'name' => 'Phalcon\\Http\\Message\\AbstractCommon',
        'file' => '/app/phalcon/Http/Message/Uri.zep',
        'line' => 20,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Uri.zep',
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
        'file' => '/app/phalcon/Http/Message/Uri.zep',
        'line' => 21,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Http/Message/Uri.zep',
    'line' => 25,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-7 Uri
 *',
    'file' => '/app/phalcon/Http/Message/Uri.zep',
    'line' => 26,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Uri',
    'abstract' => 0,
    'final' => 1,
    'extends' => 'AbstractCommon',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'UriInterface',
        'file' => '/app/phalcon/Http/Message/Uri.zep',
        'line' => 27,
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
          'name' => 'fragment',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 33,
            'char' => 25,
          ),
          'docblock' => '**
     * Returns the fragment of the URL
     *
     * @return string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 33,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 46,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'host',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 47,
            'char' => 21,
          ),
          'docblock' => '**
     * Retrieve the host component of the URI.
     *
     * If no host is present, this method MUST return an empty string.
     *
     * The value returned MUST be normalized to lowercase, per RFC 3986
     * Section 3.2.2.
     *
     * @see http://tools.ietf.org/html/rfc3986#section-3.2.2
     *
     * @return string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 47,
              'char' => 27,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 51,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'pass',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 52,
            'char' => 20,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 58,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'path',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 59,
            'char' => 21,
          ),
          'docblock' => '**
     * Returns the path of the URL
     *
     * @return string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 59,
              'char' => 27,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 75,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'port',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 76,
            'char' => 25,
          ),
          'docblock' => '**
     * Retrieve the port component of the URI.
     *
     * If a port is present, and it is non-standard for the current scheme,
     * this method MUST return it as an integer. If the port is the standard
     * port used with the current scheme, this method SHOULD return null.
     *
     * If no port is present, and no scheme is present, this method MUST return
     * a null value.
     *
     * If no port is present, but a scheme is present, this method MAY return
     * the standard port for that scheme, but SHOULD return null.
     *
     * @return int|null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 76,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 82,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'query',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 83,
            'char' => 22,
          ),
          'docblock' => '**
     * Returns the query of the URL
     *
     * @return string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 83,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 99,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'scheme',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'https',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 100,
            'char' => 28,
          ),
          'docblock' => '**
     * Retrieve the scheme component of the URI.
     *
     * If no scheme is present, this method MUST return an empty string.
     *
     * The value returned MUST be normalized to lowercase, per RFC 3986
     * Section 3.1.
     *
     * The trailing ":" character is not part of the scheme and MUST NOT be
     * added.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-3.1
     *
     * @return string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 100,
              'char' => 34,
            ),
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 104,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'user',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 105,
            'char' => 20,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 111,
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
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 112,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 112,
              'char' => 47,
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
                  'variable' => 'urlParts',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 114,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 116,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 116,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'uri',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 116,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 116,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 116,
                'char' => 30,
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
                      'variable' => 'urlParts',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'parse_url',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'uri',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 117,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 117,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 117,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 117,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 119,
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 119,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'urlParts',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 119,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 119,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 119,
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
                          'variable' => 'urlParts',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 120,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 120,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 121,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 123,
                  'char' => 15,
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
                      'property' => 'fragment',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 123,
                          'char' => 39,
                        ),
                        'name' => 'filterFragment',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 123,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 123,
                                  'char' => 72,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'fragment',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 123,
                                    'char' => 82,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 123,
                                  'char' => 82,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 123,
                                    'char' => 84,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 123,
                                  'char' => 84,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 123,
                              'char' => 85,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 123,
                            'char' => 85,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 123,
                        'char' => 86,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 123,
                      'char' => 86,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'host',
                      'expr' => 
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
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 124,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 124,
                                  'char' => 62,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'host',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 124,
                                    'char' => 68,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 124,
                                  'char' => 68,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 124,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 124,
                                  'char' => 70,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 124,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 124,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 124,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 124,
                      'char' => 72,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'pass',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'rawurlencode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 125,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 125,
                                  'char' => 64,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'pass',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 125,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 125,
                                  'char' => 70,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 125,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 125,
                                  'char' => 72,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 125,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 125,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 125,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 125,
                      'char' => 74,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'path',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 126,
                          'char' => 39,
                        ),
                        'name' => 'filterPath',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 126,
                                    'char' => 68,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 126,
                                  'char' => 68,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'path',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 126,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 126,
                                  'char' => 74,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 126,
                                    'char' => 76,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 126,
                                  'char' => 76,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 126,
                              'char' => 77,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 126,
                            'char' => 77,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 126,
                        'char' => 78,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 126,
                      'char' => 78,
                    ),
                    4 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'port',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 127,
                          'char' => 39,
                        ),
                        'name' => 'filterPort',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 127,
                                    'char' => 68,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 127,
                                  'char' => 68,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'port',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 127,
                                    'char' => 74,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 127,
                                  'char' => 74,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'null',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 127,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 127,
                                  'char' => 80,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 127,
                              'char' => 81,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 127,
                            'char' => 81,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 127,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 127,
                      'char' => 82,
                    ),
                    5 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'query',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 128,
                          'char' => 39,
                        ),
                        'name' => 'filterQuery',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 128,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 128,
                                  'char' => 69,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'query',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 128,
                                    'char' => 76,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 128,
                                  'char' => 76,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 128,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 128,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 128,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 128,
                            'char' => 79,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 128,
                        'char' => 80,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 128,
                      'char' => 80,
                    ),
                    6 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'scheme',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 129,
                          'char' => 39,
                        ),
                        'name' => 'filterScheme',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 129,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 129,
                                  'char' => 70,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'scheme',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 129,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 129,
                                  'char' => 78,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 129,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 129,
                                  'char' => 80,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 129,
                              'char' => 81,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 129,
                            'char' => 81,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 129,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 129,
                      'char' => 82,
                    ),
                    7 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'user',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'rawurlencode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Arr',
                              'dynamic' => 0,
                              'name' => 'get',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'urlParts',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 130,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 130,
                                  'char' => 64,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'user',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 130,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 130,
                                  'char' => 70,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 130,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 130,
                                  'char' => 72,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 130,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 130,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 130,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 130,
                      'char' => 74,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 131,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 132,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Uri constructor.
     *
     * @param string $uri
     *',
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 112,
          'last-line' => 143,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__toString',
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
                  'variable' => 'authority',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 146,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 146,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'uri',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 146,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 148,
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
                  'variable' => 'authority',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 148,
                      'char' => 30,
                    ),
                    'name' => 'getAuthority',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 148,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 148,
                  'char' => 45,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 149,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 149,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 149,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 149,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 160,
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
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 160,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 160,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 160,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 160,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'starts_with',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'path',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 160,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 160,
                              'char' => 60,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '/',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 160,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 160,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 160,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 160,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 160,
                      'char' => 66,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 160,
                        'char' => 71,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'authority',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 160,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 160,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 160,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 160,
                  'char' => 84,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 160,
                'char' => 84,
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
                      'variable' => 'path',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '/',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 161,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 161,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 161,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 161,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 162,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 164,
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
                  'variable' => 'uri',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 164,
                              'char' => 24,
                            ),
                            'name' => 'checkValue',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'property-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 164,
                                    'char' => 41,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'scheme',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 164,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 164,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 164,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '',
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 164,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 164,
                                'char' => 50,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ':',
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 164,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 164,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 165,
                            'char' => 17,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 165,
                              'char' => 24,
                            ),
                            'name' => 'checkValue',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'authority',
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 165,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 165,
                                'char' => 45,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '//',
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 165,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 165,
                                'char' => 49,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 166,
                            'char' => 17,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 166,
                          'char' => 17,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 167,
                          'char' => 17,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 167,
                        'char' => 17,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 167,
                          'char' => 24,
                        ),
                        'name' => 'checkValue',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 167,
                                'char' => 41,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'query',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 167,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 167,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 167,
                            'char' => 47,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '?',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 167,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 167,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 168,
                        'char' => 17,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 168,
                      'char' => 17,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 168,
                        'char' => 24,
                      ),
                      'name' => 'checkValue',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 168,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'fragment',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 168,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 168,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 168,
                          'char' => 50,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '#',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 168,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 168,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 168,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 168,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 168,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 170,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'uri',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 170,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 171,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the string representation as a URI reference.
     *
     * Depending on which components of the URI are present, the resulting
     * string is either a full URI or relative reference according to RFC 3986,
     * Section 4.1. The method concatenates the various components of the URI,
     * using the appropriate delimiters
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 145,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 145,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 144,
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
          'name' => 'getAuthority',
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
                  'variable' => 'authority',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 180,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'userInfo',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 180,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 186,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 186,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 186,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 186,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 186,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 186,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 186,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 187,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 190,
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
                  'variable' => 'authority',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 190,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 190,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 190,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 190,
                  'char' => 35,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'userInfo',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 191,
                      'char' => 30,
                    ),
                    'name' => 'getUserInfo',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 191,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 191,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 198,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 198,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'userInfo',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 198,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 198,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 198,
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
                      'variable' => 'authority',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'userInfo',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 199,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '@',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 199,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 199,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'authority',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 199,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 199,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 199,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 200,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 206,
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
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 206,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 206,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'port',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 206,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 206,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 206,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 206,
                'char' => 41,
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
                      'variable' => 'authority',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 207,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 207,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'port',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 207,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 207,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 207,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 207,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 208,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 210,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'authority',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 210,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 211,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieve the authority component of the URI.
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 179,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 179,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 178,
          'last-line' => 227,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getUserInfo',
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 230,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 230,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pass',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 230,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 230,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 230,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 230,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 230,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 230,
                'char' => 48,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 231,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'user',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 231,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 231,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ':',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 231,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 231,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 231,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'pass',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 231,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 231,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 231,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 232,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 234,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 234,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'user',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 234,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 234,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 235,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieve the user information component of the URI.
     *
     * If no user information is present, this method MUST return an empty
     * string.
     *
     * If a user is present in the URI, this will return that value;
     * additionally, if the password is also present, it will be appended to the
     * user value, with a colon (":") separating the values.
     *
     * The trailing "@" character is not part of the user information and MUST
     * NOT be added.
     *
     * @return string The URI user information, in "username[:password]" format.
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 229,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 229,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 228,
          'last-line' => 251,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withFragment',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'fragment',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 252,
              'char' => 46,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 254,
                  'char' => 14,
                ),
                'name' => 'checkStringParameter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fragment',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 254,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 254,
                    'char' => 44,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 254,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 256,
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
                  'variable' => 'fragment',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 256,
                      'char' => 29,
                    ),
                    'name' => 'filterFragment',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fragment',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 256,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 256,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 256,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 256,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 258,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 258,
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
                      'value' => 'fragment',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 258,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 258,
                    'char' => 44,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'fragment',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 258,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 258,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 258,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 259,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified URI fragment.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified URI fragment.
     *
     * Users can provide both encoded and decoded fragment characters.
     * Implementations ensure the correct encoding as outlined in getFragment().
     *
     * An empty fragment value is equivalent to removing the fragment.
     *
     * @param string $fragment
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 253,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 253,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 253,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 252,
          'last-line' => 283,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 284,
              'char' => 38,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 286,
                  'char' => 14,
                ),
                'name' => 'checkStringParameter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 286,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 286,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 286,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 288,
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
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 288,
                        'char' => 30,
                      ),
                      'right' => 
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
                              'value' => 'path',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 288,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 288,
                            'char' => 43,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '?',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 288,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 288,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 288,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 288,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 288,
                        'char' => 59,
                      ),
                      'right' => 
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
                              'value' => 'path',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 288,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 288,
                            'char' => 72,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '#',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 288,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 288,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 288,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 288,
                      'char' => 76,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 288,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 288,
                  'char' => 78,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 288,
                'char' => 78,
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
                          'value' => 'Path cannot contain a query string or fragment',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 291,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 291,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 291,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 292,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 294,
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
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 294,
                      'char' => 25,
                    ),
                    'name' => 'filterPath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 294,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 294,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 294,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 294,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 296,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 296,
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
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 296,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 296,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 296,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 296,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 296,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 297,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified path.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified path.
     *
     * The path can either be empty or absolute (starting with a slash) or
     * rootless (not starting with a slash). Implementations MUST support all
     * three syntaxes.
     *
     * If an HTTP path is intended to be host-relative rather than path-relative
     * then it must begin with a slash ("/"). HTTP paths not starting with a
     * slash are assumed to be relative to some base path known to the
     * application or consumer.
     *
     * Users can provide both encoded and decoded path characters.
     * Implementations ensure the correct encoding as outlined in getPath().
     *
     * @param string $path
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid paths.
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 285,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 285,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 285,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 284,
          'last-line' => 315,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withPort',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'port',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 316,
              'char' => 38,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 318,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'port',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 318,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 318,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 318,
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
                      'variable' => 'port',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 319,
                          'char' => 29,
                        ),
                        'name' => 'filterPort',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'port',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 319,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 319,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 319,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 319,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 321,
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
                          'type' => 'not-identical',
                          'left' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 321,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'port',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 321,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 321,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'or',
                            'left' => 
                            array (
                              'type' => 'less',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'port',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 321,
                                'char' => 49,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 321,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 321,
                              'char' => 54,
                            ),
                            'right' => 
                            array (
                              'type' => 'greater',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'port',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 321,
                                'char' => 61,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '65535',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 321,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 321,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 321,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 321,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 321,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 321,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 321,
                    'char' => 71,
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
                              'value' => 'Method expects valid port (1-65535)',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 324,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 324,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 324,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 325,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 326,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 328,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 328,
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
                      'value' => 'port',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 328,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 328,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'port',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 328,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 328,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 328,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 329,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified port.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified port.
     *
     * Implementations MUST raise an exception for ports outside the
     * established TCP and UDP port ranges.
     *
     * A null value provided for the port is equivalent to removing the port
     * information.
     *
     * @param int|null $port
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid ports.
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 317,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 317,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 317,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 316,
          'last-line' => 346,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withQuery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'query',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 347,
              'char' => 40,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 349,
                  'char' => 14,
                ),
                'name' => 'checkStringParameter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'query',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 349,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 349,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 349,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 351,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 351,
                    'char' => 29,
                  ),
                  'right' => 
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
                          'value' => 'query',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 351,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 351,
                        'char' => 43,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '#',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 351,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 351,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 351,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 351,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 351,
                'char' => 48,
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
                          'value' => 'Query cannot contain a query fragment',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 354,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 354,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 354,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 355,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 357,
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
                  'variable' => 'query',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 357,
                      'char' => 26,
                    ),
                    'name' => 'filterQuery',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'query',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 357,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 357,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 357,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 357,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 359,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 359,
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
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 359,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 359,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'query',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 359,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 359,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 359,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 360,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified query string.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified query string.
     *
     * Users can provide both encoded and decoded query characters.
     * Implementations ensure the correct encoding as outlined in getQuery().
     *
     * An empty query string value is equivalent to removing the query string.
     *
     * @param string $query
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid query strings.
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 348,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 348,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 348,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 347,
          'last-line' => 378,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withScheme',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'scheme',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 379,
              'char' => 38,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 381,
                  'char' => 14,
                ),
                'name' => 'checkStringParameter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'scheme',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 381,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 381,
                    'char' => 42,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 381,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 383,
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
                  'variable' => 'scheme',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 383,
                      'char' => 27,
                    ),
                    'name' => 'filterScheme',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'scheme',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 383,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 383,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 383,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 383,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 385,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 385,
                  'char' => 21,
                ),
                'name' => 'processWith',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'scheme',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 385,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 385,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'scheme',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 385,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 385,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 385,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 386,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified scheme.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified scheme.
     *
     * Implementations MUST support the schemes "http" and "https" case
     * insensitively, and MAY accommodate other schemes if required.
     *
     * An empty scheme is equivalent to removing the scheme.
     *
     * @param string $scheme
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid schemes.
     * @throws InvalidArgumentException for unsupported schemes.
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 380,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 380,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 380,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 379,
          'last-line' => 395,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withUserInfo',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'user',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 396,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'password',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 396,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 396,
              'char' => 63,
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
                  'variable' => 'newInstance',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 398,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 400,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 400,
                  'char' => 14,
                ),
                'name' => 'checkStringParameter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'user',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 400,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 400,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 400,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 402,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 402,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'password',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 402,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 402,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 402,
                'char' => 39,
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
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 403,
                      'char' => 18,
                    ),
                    'name' => 'checkStringParameter',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'user',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 403,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 403,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 403,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 404,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 406,
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
                  'variable' => 'user',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'rawurlencode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'user',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 406,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 406,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 406,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 406,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 408,
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
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 408,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'password',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 408,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 408,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 408,
                'char' => 39,
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
                      'variable' => 'password',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'rawurlencode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'password',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 409,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 409,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 409,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 409,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 410,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 415,
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
                  'variable' => 'newInstance',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 415,
                      'char' => 38,
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
                          'value' => 'user',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 415,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 415,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'user',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 415,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 415,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 415,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 415,
                  'char' => 64,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'newInstance',
                  'property' => 'pass',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'password',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 416,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 416,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 418,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'newInstance',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 418,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 419,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified user information.
     *
     * @param string      $user
     * @param string|null $password
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 397,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 397,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 397,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 396,
          'last-line' => 434,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'withHost',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'host',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 435,
              'char' => 34,
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
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 437,
                  'char' => 21,
                ),
                'name' => 'processWith',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 437,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 437,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 437,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 437,
                    'char' => 44,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 437,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 438,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return an instance with the specified host.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified host.
     *
     * An empty host value is equivalent to removing the host.
     *
     * @param string $host
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid hostnames.
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
                  'value' => 'Uri',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 436,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 436,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 436,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 435,
          'last-line' => 449,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'checkValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 451,
              'char' => 22,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'prefix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 452,
                'char' => 26,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 452,
              'char' => 26,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'suffix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 454,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 454,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 456,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 456,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 456,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 456,
                'char' => 32,
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
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'prefix',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 457,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 457,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 457,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'suffix',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 457,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 457,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 457,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 458,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 460,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 460,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 461,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * If the value passed is empty it returns it prefixed and suffixed with
     * the passed parameters
     *
     * @param string $value
     * @param string $prefix
     * @param string $suffix
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 455,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 455,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 450,
          'last-line' => 479,
          'char' => 20,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'filterFragment',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'fragment',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 480,
              'char' => 53,
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
                'name' => 'rawurlencode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fragment',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 482,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 482,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 482,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 483,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * If no fragment is present, this method MUST return an empty string.
     *
     * The leading "#" character is not part of the fragment and MUST NOT be
     * added.
     *
     * The value returned MUST be percent-encoded, but MUST NOT double-encode
     * any characters. To determine what characters to encode, please refer to
     * RFC 3986, Sections 2 and 3.5.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-2
     * @see https://tools.ietf.org/html/rfc3986#section-3.5
     *
     * @param string $fragment
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 481,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 481,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 480,
          'last-line' => 511,
          'char' => 20,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'filterPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 512,
              'char' => 45,
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
                  'variable' => 'element',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 514,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 514,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'parts',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 514,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 516,
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 516,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 516,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 516,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 516,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'starts_with',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'path',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 516,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 516,
                            'char' => 60,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '/',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 516,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 516,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 516,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 516,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 516,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 516,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 516,
                'char' => 66,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 517,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 518,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 520,
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
                  'variable' => 'parts',
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
                          'value' => '/',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 520,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 520,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 520,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 520,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 520,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 520,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 521,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'parts',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 521,
                'char' => 35,
              ),
              'key' => 'key',
              'value' => 'element',
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parts',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 522,
                          'char' => 26,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'rawurlencode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'element',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 522,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 522,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 522,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 522,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 523,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 525,
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
                  'variable' => 'path',
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
                          'value' => '/',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 525,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 525,
                        'char' => 29,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'parts',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 525,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 525,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 525,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 525,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 527,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => '/',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 527,
                  'char' => 18,
                ),
                'right' => 
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
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 527,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 527,
                      'char' => 30,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '/',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 527,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 527,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 527,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 527,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 528,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     *
     * The path can either be empty or absolute (starting with a slash) or
     * rootless (not starting with a slash). Implementations MUST support all
     * three syntaxes.
     *
     * Normally, the empty path "" and absolute path "/" are considered equal as
     * defined in RFC 7230 Section 2.7.3. But this method MUST NOT automatically
     * do this normalization because in contexts with a trimmed base path, e.g.
     * the front controller, this difference becomes significant. It\'s the task
     * of the user to handle both "" and "/".
     *
     * The value returned MUST be percent-encoded, but MUST NOT double-encode
     * any characters. To determine what characters to encode, please refer to
     * RFC 3986, Sections 2 and 3.3.
     *
     * As an example, if the value should include a slash ("/") not intended as
     * delimiter between path segments, that value MUST be passed in encoded
     * form (e.g., "%2F") to the instance.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-2
     * @see https://tools.ietf.org/html/rfc3986#section-3.3
     *
     * @param string $path
     *
     * @return string The URI path.
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 513,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 513,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 512,
          'last-line' => 536,
          'char' => 20,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'filterPort',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'port',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 537,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'ports',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 539,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 541,
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
                  'variable' => 'ports',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '80',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 542,
                          'char' => 17,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 542,
                          'char' => 20,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 542,
                        'char' => 20,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'int',
                          'value' => '443',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 543,
                          'char' => 17,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 544,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 544,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 544,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 544,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 546,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 546,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'port',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 546,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 546,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 546,
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
                      'variable' => 'port',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'port',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 547,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 547,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 547,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 548,
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
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ports',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 548,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'port',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 548,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 548,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 548,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 548,
                    'char' => 43,
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
                          'variable' => 'port',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 549,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 549,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 550,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 551,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 553,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'port',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 553,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 554,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the port. If it is a standard one (80,443) then it returns null
     *
     * @param $port
     *
     * @return int|null
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 538,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 538,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 537,
          'last-line' => 576,
          'char' => 20,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'filterQuery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'query',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 577,
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
                  'variable' => 'index',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 579,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'part',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 579,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'parts',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 579,
                  'char' => 31,
                ),
                3 => 
                array (
                  'variable' => 'split',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 579,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 581,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 581,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'query',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 581,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 581,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 581,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 582,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 583,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 585,
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
                  'variable' => 'query',
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
                          'type' => 'variable',
                          'value' => 'query',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 585,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 585,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '?',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 585,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 585,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 585,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 585,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'parts',
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
                          'value' => '&',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 586,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 586,
                        'char' => 30,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'query',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 586,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 586,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 586,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 586,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 588,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'parts',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 588,
                'char' => 34,
              ),
              'key' => 'index',
              'value' => 'part',
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
                      'variable' => 'split',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 589,
                          'char' => 30,
                        ),
                        'name' => 'splitQueryValue',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'part',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 589,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 589,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 589,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 589,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 590,
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 590,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'split',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 590,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 590,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 590,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 590,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 590,
                    'char' => 43,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'parts',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 591,
                              'char' => 32,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'rawurlencode',
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
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 591,
                                    'char' => 54,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 591,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 591,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 591,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 591,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 591,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 592,
                      'char' => 24,
                    ),
                    1 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 593,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 595,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parts',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 595,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'rawurlencode',
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
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 595,
                                    'char' => 50,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 595,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 595,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 595,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 595,
                            'char' => 55,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '=',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 595,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 595,
                          'char' => 59,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'rawurlencode',
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
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 595,
                                  'char' => 79,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 595,
                                  'char' => 81,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 595,
                                'char' => 82,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 595,
                              'char' => 82,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 595,
                          'char' => 83,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 595,
                        'char' => 83,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 595,
                      'char' => 83,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 596,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 598,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
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
                      'value' => '&',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 598,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 598,
                    'char' => 25,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parts',
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 598,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 598,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 598,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 599,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * If no query string is present, this method MUST return an empty string.
     *
     * The leading "?" character is not part of the query and MUST NOT be
     * added.
     *
     * The value returned MUST be percent-encoded, but MUST NOT double-encode
     * any characters. To determine what characters to encode, please refer to
     * RFC 3986, Sections 2 and 3.4.
     *
     * As an example, if a value in a key/value pair of the query string should
     * include an ampersand ("&") not intended as a delimiter between values,
     * that value MUST be passed in encoded form (e.g., "%26") to the instance.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-2
     * @see https://tools.ietf.org/html/rfc3986#section-3.4
     *
     * @param string $query
     *
     * @return string The URI query string.
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 578,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 578,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 577,
          'last-line' => 607,
          'char' => 20,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'filterScheme',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'scheme',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 608,
              'char' => 49,
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
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 610,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 611,
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
                  'variable' => 'schemes',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 611,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 613,
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
                  'variable' => 'filtered',
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
                          'value' => '#:(//)?$#',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 613,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 613,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 613,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 613,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'mb_strtolower',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'scheme',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 613,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 613,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 613,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 613,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 613,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 613,
                  'char' => 72,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'schemes',
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
                          'value' => 'http',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 615,
                          'char' => 23,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 615,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 615,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'https',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 616,
                          'char' => 23,
                        ),
                        'value' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 617,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 617,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 617,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 617,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 619,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 619,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filtered',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 619,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 619,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 619,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 620,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 621,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 623,
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'schemes',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 623,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filtered',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 623,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 623,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 623,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 623,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 623,
                'char' => 46,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'Unsupported scheme [',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 625,
                                    'char' => 38,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'filtered',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 625,
                                    'char' => 49,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 625,
                                  'char' => 49,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ']. ',
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 625,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 625,
                                'char' => 55,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'Scheme must be one of [',
                                'file' => '/app/phalcon/Http/Message/Uri.zep',
                                'line' => 626,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 626,
                              'char' => 41,
                            ),
                            'right' => 
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
                                    'value' => ', ',
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 627,
                                    'char' => 27,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 627,
                                  'char' => 27,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'array_keys',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'schemes',
                                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                                          'line' => 627,
                                          'char' => 47,
                                        ),
                                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                                        'line' => 627,
                                        'char' => 47,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                                    'line' => 627,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                                  'line' => 627,
                                  'char' => 48,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Message/Uri.zep',
                              'line' => 627,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 627,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ']',
                            'file' => '/app/phalcon/Http/Message/Uri.zep',
                            'line' => 628,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 628,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 628,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 628,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 629,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 631,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'scheme',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 631,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 632,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Filters the passed scheme - only allowed schemes
     *
     * @param string $scheme
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 609,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 609,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 608,
          'last-line' => 638,
          'char' => 20,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'splitQueryValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 639,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 641,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 643,
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
                  'variable' => 'data',
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
                          'value' => '=',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 643,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 643,
                        'char' => 29,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'element',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 643,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 643,
                        'char' => 38,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Http/Message/Uri.zep',
                          'line' => 643,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 643,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 643,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 643,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 644,
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 644,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 644,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 644,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Message/Uri.zep',
                    'line' => 644,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 644,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 644,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Http/Message/Uri.zep',
                        'line' => 645,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Http/Message/Uri.zep',
                      'line' => 645,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Message/Uri.zep',
                  'line' => 646,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 648,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 648,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Message/Uri.zep',
              'line' => 649,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param string $element
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
                'file' => '/app/phalcon/Http/Message/Uri.zep',
                'line' => 640,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Message/Uri.zep',
            'line' => 640,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Message/Uri.zep',
          'line' => 639,
          'last-line' => 650,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Http/Message/Uri.zep',
      'line' => 26,
      'char' => 11,
    ),
    'file' => '/app/phalcon/Http/Message/Uri.zep',
    'line' => 26,
    'char' => 11,
  ),
);